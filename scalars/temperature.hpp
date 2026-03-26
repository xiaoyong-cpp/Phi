#ifndef PHI_SCALARS_TEMPERATURE_HPP
#define PHI_SCALARS_TEMPERATURE_HPP

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

        Scalar* clone() const override {
            auto result = new Temperature();
            result->value = value;
            return result;
        }
    };
    
    Temperature operator"" _K(Pure value) {
        return Temperature(value);
    }
}

#endif
