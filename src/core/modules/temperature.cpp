#include "../registry.hpp"

void registerTemperature(UnitRegistry& r) {
    r.addCategory({.id = "temperature", .base_unit = "kelvin"});

    r.addUnit({.id = "kelvin",
               .symbol = "K",
               .category = "temperature",
               .scale = 1.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "celcius",
               .symbol = "C",
               .category = "temperature",
               .scale = 1.0,
               .offset = 273.15,
               .inv_scale = 0.0,
               .description = "K = C + 273.15"});
    r.addUnit({.id = "fahrenheit",
               .symbol = "F",
               .category = "temperature",
               .scale = 5.0 / 9.0,
               .offset = 273.15 - (32.0 * 5.0 / 9.0),
               .inv_scale = 0.0,
               .description = "K = (F - 32) * 5/9 + 273.15"});
    r.addUnit({.id = "rankine",
               .symbol = "R",
               .category = "kelvin",
               .scale = 5.0 / 9.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = "R = F + 459.67"});
}