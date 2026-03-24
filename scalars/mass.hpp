#ifndef SCALARS_MASS_HPP
#define SCALARS_MASS_HPP

#include "base.hpp"

namespace phi {
    class Mass : public Scalar {
    public:
        Mass() {
            dimensions[DIM_MASS] = 1.0; 
            name = "Kilogram";
            symbol = "kg";
        }

        Mass(Pure value) {
            dimensions = {};
            dimensions[DIM_MASS] = 1.0; 
            name = "Kilogram";
            symbol = "kg";
            this->value = value;
        }

        std::shared_ptr<Scalar> clone() const override {
            auto result = std::make_shared<Mass>();
            result->value = value;
            return result;
        }
    };
    
    Mass operator"" _kg(Pure value) {
        return Mass(value);
    }
}

#endif
