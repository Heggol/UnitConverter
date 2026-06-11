#include "../registry.hpp"

void registerEnergy(UnitRegistry& r) {
    r.addCategory({.id = "energy", .base_unit = "joule"});

    r.addUnit({.id = "joule",
               .symbol = "J",
               .category = "energy",
               .scale = 1.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
}