#include "../registry.hpp"

void registerMass(UnitRegistry& r) {
    r.addCategory({.id = "mass", .base_unit = "kilogram"});

    r.addUnit({.id = "kilogram",
               .symbol = "kg",
               .category = "mass",
               .scale = 1.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "gram",
               .symbol = "g",
               .category = "mass",
               .scale = 0.001,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "pound",
               .symbol = "lb",
               .category = "mass",
               .scale = 0.45359237,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
}