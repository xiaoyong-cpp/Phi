#ifndef DIMENSIONS_MASS_HPP
#define DIMENSIONS_MASS_HPP

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
    };
    
    Mass operator"" _kg(Pure value) {
        return Mass(value);
    }
}

#endif
