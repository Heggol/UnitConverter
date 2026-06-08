#include "../registry.hpp"

void registerData(UnitRegistry& r) {
  r.addCategory({ "data", "byte" });

  r.addUnit({ "bit",      "b",      "data", 0.125,     0.0, 0.0, "" });
  r.addUnit({ "nibble",   "nibble", "data", 0.5,       0.0, 0.0, "" });
  r.addUnit({ "byte",     "B",      "data", 1.0,       0.0, 0.0, "" });

  r.addUnit({ "kilobit",  "Kb",     "data", 125.0,     0.0, 0.0, "" });
  r.addUnit({ "kibibit",  "Kibit",  "data", 128.0,     0.0, 0.0, "" });
  r.addUnit({ "kilobyte", "KB",     "data", 1000.0,    0.0, 0.0, "" });
  r.addUnit({ "kibibyte", "KiB",    "data", 1024.0,    0.0, 0.0, "" });

  r.addUnit({ "megabit",  "Mb",     "data", 125000.0,  0.0, 0.0, "" });
  r.addUnit({ "mebibit",  "Mibit",  "data", 131072.0,  0.0, 0.0, "" });
  r.addUnit({ "megabyte", "MB",     "data", 1000000.0, 0.0, 0.0, "" });
  r.addUnit({ "mebibyte", "MiB",    "data", 1048576.0, 0.0, 0.0, "" });
}