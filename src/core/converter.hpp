#ifndef UNITCONVERTER_SRC_CORE_CONVERTER_HPP_
#define UNITCONVERTER_SRC_CORE_CONVERTER_HPP_
#include <string>

#include "registry.hpp"

class UnitConverter {
   public:
    explicit UnitConverter(const UnitRegistry& registry);

    [[nodiscard]] double convert(double value, const std::string& from, const std::string& to) const;
    [[nodiscard]] double convertBFS(double value, const std::string& from, const std::string& to) const;

   private:
    const UnitRegistry* registry;
};

#endif