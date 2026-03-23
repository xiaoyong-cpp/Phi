#ifndef SCALARS_TEMPERATURE_HPP
#define SCALARS_TEMPERATURE_HPP

#include "base.hpp"

namespace phi {
    class Temperature : public Scalar {
    public:
        Temperature() {
            dimensions[DIM_TEMPERATURE] = 1.0; 
            name = "Kelvin";
            symbol = "K";
        }

        Temperature(Pure value) {
            dimensions = {};
            dimensions[DIM_TEMPERATURE] = 1.0; 
            name = "Kelvin";
            symbol = "K";
            this->value = value;
        }
    };
    
    Temperature operator"" _K(Pure value) {
        return Temperature(value);
    }
}

#endif
