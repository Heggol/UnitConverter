#pragma once
#include <string>

#include "registry.hpp"

class UnitConverter {
   public:
    explicit UnitConverter(const UnitRegistry& registry);

    [[nodiscard]] double convert(double value, const std::string& from, const std::string& to) const;

   private:
    const UnitRegistry* registry;
};