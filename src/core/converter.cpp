#include "converter.hpp"

#include <queue>
#include <stdexcept>
#include <unordered_set>

UnitConverter::UnitConverter(const UnitRegistry& registry) : registry(registry) {}

double UnitConverter::convert(double value, const std::string& from, const std::string& to) const {
    const Unit& A = registry.getUnit(from);
    const Unit& B = registry.getUnit(to);

    if (A.category != B.category) {
        throw std::invalid_argument("Cannot convert between different categories");
    }

    double base = (value * A.scale) + A.offset;
    return (base - B.offset) * B.inv_scale;
}

double UnitConverter::convertBFS(double value, const std::string& from, const std::string& to) const {
    std::queue<std::pair<std::string, double>> q;
    std::unordered_set<std::string> visited;

    q.push({from, value});
    visited.insert(from);

    while (!q.empty()) {
        auto [category, current] = q.front();
        q.pop();

        if (category == to) {
            return current;
        }

        for (const auto& edge : registry.getEdges(category)) {
            if (!visited.contains(edge.to)) {
                double next = edge.forward(current);

                visited.insert(edge.to);
                q.push({edge.to, next});
            }
        }
    }

    throw std::runtime_error("No conversion path found");
}