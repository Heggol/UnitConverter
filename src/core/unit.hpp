#pragma once
#include <string>

struct Unit {
  std::string id;
  std::string symbol;
  std::string category;

  double scale;
  double offset;

  double inv_scale;

  std::string description;
};