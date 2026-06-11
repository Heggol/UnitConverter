#include "service.hpp"

#include <stdexcept>

void registerData(UnitRegistry&);
void registerEnergy(UnitRegistry&);
void registerLength(UnitRegistry&);
void registerMass(UnitRegistry&);
void registerTemperature(UnitRegistry&);
void registerVolume(UnitRegistry&);

UnitService::UnitService() : converter(registry) { registerDefaults(); }

void UnitService::registerDefaults() {
    registerData(registry);
    registerEnergy(registry);
    registerLength(registry);
    registerMass(registry);
    registerTemperature(registry);
    registerVolume(registry);

    registry.registerEdges();
}

double UnitService::convert(double value, const std::string& from, const std::string& to, Mode mode) const {
    const Unit& A = registry.getUnit(from);
    const Unit& B = registry.getUnit(to);

    if (A.category == B.category) {
        return converter.convert(value, from, to);
    }

    if (mode == Mode::Everything) {
        double base = (value * A.scale) + A.offset;
        double convertedBase = converter.convertBFS(base, A.category, B.category);
        return (convertedBase - B.offset) * B.inv_scale;
    }

    throw std::runtime_error("Different categories");
}

std::vector<std::string> UnitService::categories() const { return registry.listCategories(); }

std::vector<std::pair<std::string, std::string>> UnitService::units(const std::string& category) const {
    std::vector<std::pair<std::string, std::string>> result;

    for (const Unit* u : registry.listUnits(category)) {
        result.emplace_back(u->id, u->symbol);
    }

    return result;
}