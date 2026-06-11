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
    r.addUnit({.id = "kilojoule",
               .symbol = "kJ",
               .category = "energy",
               .scale = 1000.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "calorie",
               .symbol = "cal",
               .category = "energy",
               .scale = 4.184,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "kilocalorie",
               .symbol = "kcal",
               .category = "energy",
               .scale = 4184.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "watt hour",
               .symbol = "Wh",
               .category = "energy",
               .scale = 3600.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
    r.addUnit({.id = "kilowatt hour",
               .symbol = "kWh",
               .category = "energy",
               .scale = 3600000.0,
               .offset = 0.0,
               .inv_scale = 0.0,
               .description = ""});
}