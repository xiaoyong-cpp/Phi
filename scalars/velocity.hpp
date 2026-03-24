#ifndef PHI_SCALARS_VELOCITY_HPP
#define PHI_SCALARS_VELOCITY_HPP

#include "base.hpp"

namespace phi {
    class Velocity : public Scalar {
    public:
        Velocity() {
            dimensions[DIM_LONG] = 1.0; 
            dimensions[DIM_TIME] = -1.0; 
            name = "Meter per Second";
            symbol = "m/s";
        }

        Velocity(Pure value) {
            dimensions = {};
            dimensions[DIM_LONG] = 1.0; 
            dimensions[DIM_TIME] = -1.0; 
            name = "Meter per Second";
            symbol = "m/s";
            this->value = value;
        }

        std::shared_ptr<Scalar> clone() const override {
            auto result = std::make_shared<Velocity>();
            result->value = value;
            return result;
        }
    };
    
    Velocity operator"" _m_s(Pure value) {
        return Velocity(value);
    }
}

#endif
