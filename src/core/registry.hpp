#pragma once
#include <string>
#include <unordered_map>
#include <vector>

#include "category.hpp"
#include "unit.hpp"

class UnitRegistry {
   public:
    void addCategory(const Category& category);
    void addUnit(const Unit& unit);

    [[nodiscard]] const Unit& getUnit(const std::string& id) const;
    [[nodiscard]] const Category& getCategory(const std::string& id) const;

    [[nodiscard]] std::vector<std::string> listCategories() const;
    [[nodiscard]] std::vector<const Unit*> listUnits(const std::string& category) const;

   private:
    std::unordered_map<std::string, Category> categories;
    std::unordered_map<std::string, Unit> units;
    std::unordered_map<std::string, std::vector<const Unit*>> unitsByCategory;
};