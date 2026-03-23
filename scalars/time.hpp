#ifndef DIMENSIONS_TIME_HPP
#define DIMENSIONS_TIME_HPP

#include "base.hpp"

namespace phi {
    class Time : public Scalar {
    public:
        Time() {
            dimensions[DIM_TIME] = 1.0; 
            name = "Second";
            symbol = "s";
        }

        Time(Pure value) {
            dimensions = {};
            dimensions[DIM_TIME] = 1.0; 
            name = "Second";
            symbol = "s";
            this->value = value;
        }
    };
    
    Time operator"" _s(Pure value) {
        return Time(value);
    }
}

#endif
