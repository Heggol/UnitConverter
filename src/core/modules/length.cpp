#include "../registry.hpp"

void registerLength(UnitRegistry& r) {
    r.addCategory({.id = "length", .base_unit = "metre"});

    r.addUnit({.id = "metre",
               .symbol = "m",
               .category = "length",
               .scale = 1.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = "Base unit"});
    r.addUnit({.id = "kilometre",
               .symbol = "km",
               .category = "length",
               .scale = 1000.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "centimetre",
               .symbol = "cm",
               .category = "length",
               .scale = 0.01,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "millimetre",
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
    r.addUnit({.id = "yard",
               .symbol = "yd",
               .category = "length",
               .scale = 0.914399999,  // meter = 1.0936133 yards
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "foot",
               .symbol = "'",
               .category = "length",
               .scale = 0.3048,  // meter = 3.2808399 feet
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "inch",
               .symbol = "\"",
               .category = "length",
               .scale = 0.0254,  // meter = 39.3700787 inches
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "mil",
               .symbol = "thou",
               .category = "length",
               .scale = 0.0000254,  // thousandth of an inch
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "nautical mile",
               .symbol = "nmi",
               .category = "length",
               .scale = 1852,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
}