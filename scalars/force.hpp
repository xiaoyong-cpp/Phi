#ifndef PHI_SCALARS_FORCE_HPP
#define PHI_SCALARS_FORCE_HPP

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

        std::shared_ptr<Scalar> clone() const override {
            auto result = std::make_shared<Force>();
            result->value = value;
            return result;
        }
    };
    
    Force operator"" _N(Pure value) {
        return Force(value);
    }
}

#endif
