#include "../registry.hpp"

void registerData(UnitRegistry& r) {
    r.addCategory({.id = "data", .base_unit = "byte"});

    r.addUnit({.id = "bit",
               .symbol = "b",
               .category = "data",
               .scale = 0.125,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "nibble",
               .symbol = "nibble",
               .category = "data",
               .scale = 0.5,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});

    r.addUnit({.id = "byte",
               .symbol = "B",
               .category = "data",
               .scale = 1.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});

    r.addUnit({.id = "kilobit",
               .symbol = "Kb",
               .category = "data",
               .scale = 125.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "kibibit",
               .symbol = "Kibit",
               .category = "data",
               .scale = 128.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "kilobyte",
               .symbol = "KB",
               .category = "data",
               .scale = 1000.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "kibibyte",
               .symbol = "KiB",
               .category = "data",
               .scale = 1024.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});

    r.addUnit({.id = "megabit",
               .symbol = "Mb",
               .category = "data",
               .scale = 125000.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "mebibit",
               .symbol = "Mibit",
               .category = "data",
               .scale = 131072.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "megabyte",
               .symbol = "MB",
               .category = "data",
               .scale = 1000000.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "mebibyte",
               .symbol = "MiB",
               .category = "data",
               .scale = 1048576.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
}