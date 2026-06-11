#pragma once

#include <functional>
#include <string>

struct ConversionEdge {
    std::string to;

    std::function<double(double)> forward;
};