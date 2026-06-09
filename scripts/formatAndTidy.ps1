$ErrorActionPreference = "Stop"
Set-Location -Path "$PSScriptRoot\.."

$FormatFiles = Get-ChildItem -Path "src" -Include *.cpp, *.hpp -Recurse | Select-Object -ExpandProperty FullName
$TidyFiles = Get-ChildItem -Path "src" -Include *.cpp -Recurse | Select-Object -ExpandProperty FullName

$CcPath = "build\msvc-ninja-debug\compile_commands.json"
if (Test-Path $CcPath) {
    (Get-Content $CcPath -Raw) `
      -replace '\s*-mno-direct-extern-access\s*', ' ' `
      -replace '\s+', ' ' `
      | Set-Content $CcPath
}

& clang-format --style=file --fallback-style=none -i $FormatFiles

$MaxJobs = [Environment]::ProcessorCount

$jobs = @()
$buildPath = Resolve-Path "build\msvc-ninja-debug"

foreach ($file in $TidyFiles) {
  while (($jobs | Where-Object State -eq 'Running').Count -ge $MaxJobs) {
    $jobs | Wait-Job -Any | Out-Null
  }

  Write-Host "Processing $file..."

  $jobs += Start-Job -ScriptBlock {
    param($f, $p)

    & clang-tidy -p $p $f 2>&1
  } -ArgumentList $file, $buildPath
}

$jobs | Wait-Job | Out-Null

$results = $jobs | Receive-Job

$diagnostics = $results | Where-Object {
  $_ -match ':\d+:\d+: (warning|error):'
}

$parsed = foreach ($line in $diagnostics) {
  if ($line -match '^(.*):(\d+):\d+: (warning|error): (.*)$') {

    $file = [System.IO.Path]::GetFullPath($matches[1])
    $lineNum = $matches[2]
    $type = $matches[3]
    $msg = $matches[4]

    [PSCustomObject]@{
      File = $file
      Line = $lineNum
      Type = $type
      Message = $msg
      Key = "${file}:${lineNum}:${type}:${msg}"
    }
  }
}

$unique = $parsed | Sort-Object Key -Unique

Write-Host "----------"
Write-Host ""

foreach ($item in $unique) {
  Write-Host "[$($item.File):$($item.Line)] $($item.Type): $($item.Message)"
}

Write-Host "`nTotal unique diagnostics: $($unique.Count)"

if ($jobs | Where-Object State -eq 'Failed') {
  throw "One or more clang-tidy jobs failed"
}

$jobs | Remove-Job

Set-Location -Path "$PSScriptRoot"