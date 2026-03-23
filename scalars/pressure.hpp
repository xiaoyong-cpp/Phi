#ifndef SCALARS_PRESSURE_HPP
#define SCALARS_PRESSURE_HPP

#include "base.hpp"

namespace phi {
    class Pressure : public Scalar {
    public:
        Pressure() {
            dimensions[DIM_LONG] = -1.0; 
            dimensions[DIM_TIME] = -2.0;
            dimensions[DIM_MASS] = 1.0;
            name = "Pascal";
            symbol = "Pa";
        }

        Pressure(Pure value) {
            dimensions = {};
            dimensions[DIM_LONG] = -1.0; 
            dimensions[DIM_TIME] = -2.0;
            dimensions[DIM_MASS] = 1.0;
            name = "Pascal";
            symbol = "Pa";
            this->value = value;
        }
    };
    
    Pressure operator"" _Pa(Pure value) {
        return Pressure(value);
    }
}

#endif
