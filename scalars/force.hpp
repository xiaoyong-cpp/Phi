#ifndef SCALARS_FORCE_HPP
#define SCALARS_FORCE_HPP

#include "base.hpp"

namespace phi {
    class Force : public Scalar {
    public:
        Force() {
            dimensions[DIM_LONG] = 1.0; 
            dimensions[DIM_TIME] = -2.0;
            dimensions[DIM_MASS] = 1.0;
            name = "Newton";
            symbol = "N";
        }

        Force(Pure value) {
            dimensions = {};
            dimensions[DIM_LONG] = 1.0; 
            dimensions[DIM_TIME] = -2.0;
            dimensions[DIM_MASS] = 1.0;
            name = "Newton";
            symbol = "N";
            this->value = value;
        }
    };
    
    Force operator"" _N(Pure value) {
        return Force(value);
    }
}

#endif
