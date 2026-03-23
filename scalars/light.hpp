#ifndef SCALARS_LIGHT_HPP
#define SCALARS_LIGHT_HPP

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
    };
    
    Light operator"" _cd(Pure value) {
        return Light(value);
    }
}

#endif
