#include "edges.hpp"

// #include <cmath>

#include "registry.hpp"

constexpr double c = 299792458.0;     // Speed of light
constexpr double kB = 1.3806503e-23;  // Boltzmann constant
constexpr double water_density = 1000.0;

void UnitRegistry::registerEdges() {
    addEdge("mass", "energy", [](double m) { return m * c * c; }, [](double e) { return e / (c * c); });
    addEdge("temperature", "energy", [](double t) { return t * kB; }, [](double e) { return e / kB; });
    addEdge("volume", "mass", [](double v) { return v * water_density; }, [](double m) { return m / water_density; });

    // later
    // length (m) <-> area (m^2)
    // addEdge("length", "area", [](double l) { return l * l; }, [](double a) { return std::sqrt(a); });
}