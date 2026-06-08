#include "../registry.hpp"

void registerLength(UnitRegistry& r) {
  r.addCategory({ "length", "meter" });

  r.addUnit({ "meter", "m", "length", 1.0, 0.0, 0.0, "Base unit" });
  r.addUnit({ "kilometer", "km", "length", 1000.0, 0.0, 0.0, "" });
  r.addUnit({ "centimeter", "cm", "length", 0.01, 0.0, 0.0, "" });
  r.addUnit({ "millimeter", "mm", "length", 0.001, 0.0, 0.0, "" });
  r.addUnit({ "mile", "mi", "length", 1609.344, 0.0, 0.0, "" });
}