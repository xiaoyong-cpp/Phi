#ifndef SCALARS_ACCELERATION_HPP
#define SCALARS_ACCELERATION_HPP

#include "base.hpp"

namespace phi {
    class Acceleration : public Scalar {
    public:
        Acceleration() {
            dimensions[DIM_LONG] = 1.0; 
            dimensions[DIM_TIME] = -2.0; 
            name = "Meter per Second per Second";
            symbol = "m/s^2";
        }

        Acceleration(Pure value) {
            dimensions = {};
            dimensions[DIM_LONG] = 1.0; 
            dimensions[DIM_TIME] = -2.0; 
            name = "Meter per Second per Second";
            symbol = "m/s^2";
            this->value = value;
        }

        std::shared_ptr<Scalar> clone() const override {
            auto result = std::make_shared<Acceleration>();
            result->value = value;
            return result;
        }
    };
    
    Acceleration operator"" _m_s2(Pure value) {
        return Acceleration(value);
    }
}

#endif
