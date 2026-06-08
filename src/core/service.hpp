#pragma once
#include "converter.hpp"
#include "registry.hpp"

enum class Mode { Strict, Everything };

class UnitService {
   public:
    UnitService();

    double convert(double value, const std::string& from, const std::string& to, Mode mode = Mode::Strict) const;

    std::vector<std::string> categories() const;

    std::vector<std::pair<std::string, std::string>> units(const std::string& category) const;

   private:
    UnitRegistry registry;
    UnitConverter converter;

    void registerDefaults();
};