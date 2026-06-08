#include "../registry.hpp"

void registerMass(UnitRegistry& r) {
  r.addCategory({ "mass", "kilogram" });

  r.addUnit({ "kilogram", "kg", "mass", 1.0, 0.0, 0.0, "" });
  r.addUnit({ "gram", "g", "mass", 0.001, 0.0, 0.0, "" });
  r.addUnit({ "pound", "lb", "mass", 0.45359237, 0.0, 0.0, "" });
}