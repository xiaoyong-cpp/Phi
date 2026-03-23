#ifndef SCALARS_CURRENT_HPP
#define SCALARS_CURRENT_HPP

#include "base.hpp"

namespace phi {
    class Current : public Scalar {
    public:
        Current() {
            dimensions[DIM_CURRENT] = 1.0; 
            name = "Ampere";
            symbol = "A";
        }

        Current(Pure value) {
            dimensions = {};
            dimensions[DIM_CURRENT] = 1.0; 
            name = "Ampere";
            symbol = "A";
            this->value = value;
        }
    };
    
    Current operator"" _A(Pure value) {
        return Current(value);
    }
}

#endif
