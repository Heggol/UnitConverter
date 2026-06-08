#include "registry.hpp"

#include <ranges>
#include <stdexcept>

void UnitRegistry::addCategory(const Category& category) { categories[category.id] = category; }

void UnitRegistry::addUnit(const Unit& unit) {
    Unit u = unit;
    u.inv_scale = 1.0 / u.scale;

    units[u.id] = u;
    unitsByCategory[u.category].push_back(&units[u.id]);
}

const Unit& UnitRegistry::getUnit(const std::string& id) const {
    auto it = units.find(id);
    if (it == units.end()) {
        throw std::runtime_error("Unit not found: " + id);
    }
    return it->second;
}

const Category& UnitRegistry::getCategory(const std::string& id) const {
    auto it = categories.find(id);
    if (it == categories.end()) {
        throw std::runtime_error("Category not found: " + id);
    }
    return it->second;
}

std::vector<std::string> UnitRegistry::listCategories() const {
    std::vector<std::string> result;
    for (const auto& id : categories | std::views::keys) {
        result.push_back(id);
    }
    return result;
}

std::vector<const Unit*> UnitRegistry::listUnits(const std::string& category) const {
    auto it = unitsByCategory.find(category);
    if (it == unitsByCategory.end()) {
        return {};
    }
    return it->second;
}