#include "../registry.hpp"

void registerVolume(UnitRegistry& r) {
    r.addCategory({.id = "volume", .base_unit = "meters cubed"});

    r.addUnit({.id = "meters cubed",
               .symbol = "m³",
               .category = "volume",
               .scale = 1.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "centimeters cubed",
               .symbol = "cm³",
               .category = "volume",
               .scale = 1000000,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
}