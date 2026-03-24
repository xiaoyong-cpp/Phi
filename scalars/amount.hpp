#ifndef PHI_SCALARS_AMOUNT_HPP
#define PHI_SCALARS_AMOUNT_HPP

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

        std::shared_ptr<Scalar> clone() const override {
            auto result = std::make_shared<Amount>();
            result->value = value;
            return result;
        }
    };
    
    Amount operator"" _mol(Pure value) {
        return Amount(value);
    }
}

#endif
