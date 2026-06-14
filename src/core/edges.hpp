#ifndef UNITCONVERTER_SRC_CORE_EDGES_HPP_
#define UNITCONVERTER_SRC_CORE_EDGES_HPP_

#include <functional>
#include <string>

struct ConversionEdge {
    std::string to;

    std::function<double(double)> forward;
};

#endif