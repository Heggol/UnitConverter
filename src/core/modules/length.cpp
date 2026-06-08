#include "../registry.hpp"

void registerLength(UnitRegistry& r) {
    r.addCategory({.id = "length", .base_unit = "meter"});

    r.addUnit({.id = "meter",
               .symbol = "m",
               .category = "length",
               .scale = 1.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = "Base unit"});
    r.addUnit({.id = "kilometer",
               .symbol = "km",
               .category = "length",
               .scale = 1000.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "centimeter",
               .symbol = "cm",
               .category = "length",
               .scale = 0.01,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "millimeter",
               .symbol = "mm",
               .category = "length",
               .scale = 0.001,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "mile",
               .symbol = "mi",
               .category = "length",
               .scale = 1609.344,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
}