#include "../registry.hpp"

void registerVolume(UnitRegistry& r) {
    r.addCategory({.id = "volume", .base_unit = "meters cubed"});

    r.addUnit({.id = "meters cubed",
               .symbol = "m³", // cubed is \u00B3
               .category = "volume",
               .scale = 1.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "centimeters cubed",
               .symbol = "cm³",
               .category = "volume",
               .scale = 0.000001,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
}