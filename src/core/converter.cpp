#include "converter.hpp"

#include <stdexcept>

UnitConverter::UnitConverter(const UnitRegistry& registry) : registry(&registry) {}

double UnitConverter::convert(double value, const std::string& from, const std::string& to) const {
    const Unit& A = registry->getUnit(from);
    const Unit& B = registry->getUnit(to);

    if (A.category != B.category) {
        throw std::runtime_error("Cannot convert between different categories");
    }

    double base = (value * A.scale) + A.offset;
    return (base - B.offset) * B.inv_scale;
}