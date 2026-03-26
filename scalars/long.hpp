#ifndef SCALARS_LONG_HPP
#define SCALARS_LONG_HPP

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

        Scalar* clone() const override {
            auto result = new Long();
            result->value = value;
            return result;
        }
    };
    
    Long operator"" _m(Pure value) {
        return Long(value);
    }
}

#endif
