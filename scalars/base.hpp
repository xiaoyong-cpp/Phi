#ifndef SCALARS_BASE_HPP
#define SCALARS_BASE_HPP

#include "../defines.hpp"
#include <string>
#include <array>

namespace phi {
    using BaseDimension = std::array<Pure, 7>;
    constexpr int DIM_LONG = 0;
    constexpr int DIM_TIME = 1;
    constexpr int DIM_MASS = 2;
    constexpr int DIM_CURRENT = 3;
    constexpr int DIM_TEMPERATURE = 4;
    constexpr int DIM_AMOUNT_OF_SUBSTANTIA = 5;
    constexpr int DIM_LIGHT = 6;

    class Scalar {
    protected:
        BaseDimension dimensions;
    public:
        Pure value = 0.0;
        std::string name = "Unknown Dimension";
        std::string symbol = "uu";
        Scalar() {}
        virtual ~Scalar() = default;

        virtual Scalar* clone() const {
            return new Scalar(*this);
        }

        virtual Scalar* add(const Scalar& other) const {
            auto result = this->clone();
            result->value += other.value;
            return result;
        }

        virtual Scalar* negate() const {
            auto result = this->clone();
            result->value = -result->value;
            return result;
        }

        virtual Scalar* multiply(Pure scalar) const {
            auto result = this->clone();
            result->value *= scalar;
            return result;
        }

        Scalar operator* (const Scalar& other) const {
            Scalar result = *this;
            for(int i = 0; i < 7; i++) {
                result.dimensions[i] += other.dimensions[i];
            }
            result.value *= other.value;
            return result;
        }

        Scalar operator/ (const Scalar& other) const {
            Scalar result = *this;
            for(int i = 0; i < 7; i++) {
                result.dimensions[i] -= other.dimensions[i];
            }
            result.value /= other.value;
            return result;
        }

        Scalar operator* (Pure scalar) const {
            Scalar result = *this;
            result.value *= scalar;
            return result;
        }

        Scalar operator/ (Pure scalar) const {
            Scalar result = *this;
            result.value /= scalar;
            return result;
        }

        bool sameDimensions(const Scalar& other) const {
            for(int i = 0; i < 7; i++) {
                if(dimensions[i] != other.dimensions[i]) {
                    return false;
                }
            }
            return true;
        }
    };
}

#endif
