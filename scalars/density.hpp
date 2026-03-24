#ifndef PHI_SCALARS_DENSITY_HPP
#define PHI_SCALARS_DENSITY_HPP

#include "base.hpp"

namespace phi {
    class Density : public Scalar {
    public:
        Density() {
            dimensions[DIM_LONG] = -3.0; 
            dimensions[DIM_MASS] = 1.0;
            name = "Kilogram per Cubic Meter";
            symbol = "kg/m^3";
        }

        Density(Pure value) {
            dimensions = {};
            dimensions[DIM_LONG] = -3.0; 
            dimensions[DIM_MASS] = 1.0;
            name = "Kilogram per Cubic Meter";
            symbol = "kg/m^3";
            this->value = value;
        }

        std::shared_ptr<Scalar> clone() const override {
            auto result = std::make_shared<Density>();
            result->value = value;
            return result;
        }
    };
    
    Density operator"" _kg_m3(Pure value) {
        return Density(value);
    }
}

#endif
