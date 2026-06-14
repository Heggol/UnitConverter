#ifndef UNITCONVERTER_SRC_CORE_REGISTRY_HPP_
#define UNITCONVERTER_SRC_CORE_REGISTRY_HPP_
#include <string>
#include <unordered_map>
#include <vector>

#include "category.hpp"
#include "edges.hpp"
#include "unit.hpp"

class UnitRegistry {
   public:
    void addCategory(const Category& category);
    void addUnit(const Unit& unit);
    void addEdge(const std::string& a, const std::string& b, std::function<double(double)> a_to_b,
                 std::function<double(double)> b_to_a);

    void registerEdges();

    [[nodiscard]] const Unit& getUnit(const std::string& id) const;
    [[nodiscard]] const Category& getCategory(const std::string& id) const;
    [[nodiscard]] const std::vector<ConversionEdge>& getEdges(const std::string& category) const;

    [[nodiscard]] std::vector<std::string> listCategories() const;
    [[nodiscard]] std::vector<const Unit*> listUnits(const std::string& category) const;

   private:
    std::unordered_map<std::string, Category> categories;
    std::unordered_map<std::string, Unit> units;
    std::unordered_map<std::string, std::vector<const Unit*>> unitsByCategory;

    std::unordered_map<std::string, std::vector<ConversionEdge>> categoryGraph;
};

#endif