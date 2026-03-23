#ifndef SCALARS_AMOUNT_HPP
#define SCALARS_AMOUNT_HPP

#include "base.hpp"

namespace phi {
    class Amount : public Scalar {
    public:
        Amount() {
            dimensions[DIM_AMOUNT_OF_SUBSTANTIA] = 1.0; 
            name = "Mole";
            symbol = "mol";
        }

        Amount(Pure value) {
            dimensions = {};
            dimensions[DIM_AMOUNT_OF_SUBSTANTIA] = 1.0; 
            name = "Mole";
            symbol = "mol";
            this->value = value;
        }
    };
    
    Amount operator"" _mol(Pure value) {
        return Amount(value);
    }
}

#endif
