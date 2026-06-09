#pragma once
#include "converter.hpp"
#include "registry.hpp"

enum class Mode { Strict, Everything };

class UnitService {
   public:
    UnitService();

    [[nodiscard]] double convert(double value, const std::string& from, const std::string& to, Mode mode = Mode::Strict) const;

    [[nodiscard]] std::vector<std::string> categories() const;

    [[nodiscard]] std::vector<std::pair<std::string, std::string>> units(const std::string& category) const;

   private:
    UnitRegistry registry;
    UnitConverter converter;

    void registerDefaults();
};