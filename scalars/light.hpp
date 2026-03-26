#ifndef PHI_SCALARS_LIGHT_HPP
#define PHI_SCALARS_LIGHT_HPP

#include "base.hpp"

namespace phi {
    class Light : public Scalar {
    public:
        Light() {
            dimensions[DIM_LIGHT] = 1.0; 
            name = "Candela";
            symbol = "cd";
        }

        Light(Pure value) {
            dimensions = {};
            dimensions[DIM_LIGHT] = 1.0; 
            name = "Candela";
            symbol = "cd";
            this->value = value;
        }

        Scalar* clone() const override {
            auto result = new Light();
            result->value = value;
            return result;
        }
    };
    
    Light operator"" _cd(Pure value) {
        return Light(value);
    }
}

#endif
