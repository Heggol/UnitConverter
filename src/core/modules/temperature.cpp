#include "../registry.hpp"

void registerTemperature(UnitRegistry& r) {
  r.addCategory({ "temperature", "kelvin" });

  r.addUnit({ "kelvin", "K", "temperature", 1.0, 0.0, 0.0, "" });
  r.addUnit({ "celcius", "C", "temperature", 1.0, 273.15, 0.0, "K = C + 273.15" });
  r.addUnit({ "fahrenheit", "F", "temperature", 5.0 / 9.0, 273.15 - (32.0 * 5.0 / 9.0), 0.0, "K = (F - 32) * 5/9 + 273.15" });
}