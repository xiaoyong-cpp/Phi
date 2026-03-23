#ifndef DIMENSIONS_LONG_HPP
#define DIMENSIONS_LONG_HPP

#include "base.hpp"

namespace phi {
    class Long : public Scalar {
    public:
        Long() {
            dimensions[DIM_LONG] = 1.0; 
            name = "Meter";
            symbol = "m";
        }

        Long(Pure value) {
            dimensions = {};
            dimensions[DIM_LONG] = 1.0; 
            name = "Meter";
            symbol = "m";
            this->value = value;
        }
    };
    
    Long operator"" _m(Pure value) {
        return Long(value);
    }
}

#endif
