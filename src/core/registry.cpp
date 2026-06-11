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

void UnitRegistry::addEdge(const std::string& a, const std::string& b, std::function<double(double)> a_to_b,
                           std::function<double(double)> b_to_a) {
    categoryGraph[a].push_back({.to = b, .forward = std::move(a_to_b)});
    categoryGraph[b].push_back({.to = a, .forward = std::move(b_to_a)});
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

const std::vector<ConversionEdge>& UnitRegistry::getEdges(const std::string& category) const {
    static const std::vector<ConversionEdge> empty;

    auto it = categoryGraph.find(category);
    if (it == categoryGraph.end()) {
        return empty;
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