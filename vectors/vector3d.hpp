#ifndef PHI_VECTOR2D_HPP
#define PHI_VECTOR2D_HPP

#include "../scalars.hpp"
#include "../defines.hpp"
#include "../exceptions.hpp"
#include <string>
#include <cmath>

namespace phi {
    class Vector3D {
    public:
        Scalar* x;
        Scalar* y;
        Scalar* z;
        
        Pure angleXY() const {
            if(!x || !y || !z) {
                throw NonsensicalException("Cannot compute angle with null components");
            }
            Pure len = length();
            if(len == 0) {
                throw NonsensicalException("Cannot compute angle for zero-length vector");
            }
            return std::asin(std::abs(z->value) / len);
        }

        Pure angleYZ() const {
            if(!x || !y || !z) {
                throw NonsensicalException("Cannot compute angle with null components");
            }
            Pure len = length();
            if(len == 0) {
                throw NonsensicalException("Cannot compute angle for zero-length vector");
            }
            return std::asin(std::abs(x->value) / len);
        }

        Pure angleXZ() const {
            if(!x || !y || !z) {
                throw NonsensicalException("Cannot compute angle with null components");
            }
            Pure len = length();
            if(len == 0) {
                throw NonsensicalException("Cannot compute angle for zero-length vector");
            }
            return std::asin(std::abs(y->value) / len);
        }

        Pure length() const {
            return sqrt(y->value * y->value + x->value * x->value + z->value * z->value);
        }

        Vector3D(Scalar* __x, Scalar* __y, Scalar* __z) {
            x = __x;
            y = __y;
            z = __z;
        }

        Vector3D(const Vector3D& other)
            : x(other.x ? other.x->clone() : nullptr),
              y(other.y ? other.y->clone() : nullptr),
              z(other.z ? other.z->clone() : nullptr) {}

        Vector3D(Vector3D&& other) noexcept = default;

        Vector3D& operator=(const Vector3D& other) {
            if(this != &other) {
                x = other.x ? other.x->clone() : nullptr;
                y = other.y ? other.y->clone() : nullptr;
            }
            return *this;
        }

        Vector3D& operator=(Vector3D&& other) noexcept = default;

        Vector3D operator+(const Vector3D& other) const {
            if(!x || !y || !z || !other.x || !other.y || !other.z) {
                throw NonsensicalException("Cannot add vectors with null components");
            }
            if(!x->sameDimensions(*other.x)) {
                throw NonsensicalException("Addition of vectors with different X dimensions between " + x->name + " and " + other.x->name);
            }
            if(!y->sameDimensions(*other.y)) {
                throw NonsensicalException("Addition of vectors with different Y dimensions between " + y->name + " and " + other.y->name);
            }
            return Vector3D(x->add(*other.x), y->add(*other.y), z->add(*other.z));
        }

        Vector3D operator-() const {
            if(!x || !y || !z) {
                throw NonsensicalException("Cannot negate vector with null components");
            }
            return Vector3D(x->negate(), y->negate(), z->negate());
        }

        Vector3D operator-(const Vector3D& other) const {
            return *this + (-other);
        }

        Vector3D operator*(Pure scalar) const {
            if(!x || !y || !z) {
                throw NonsensicalException("Cannot multiply vector with null components");
            }
            return Vector3D(x->multiply(scalar), y->multiply(scalar), z->multiply(scalar));
        }

        friend Vector3D operator*(Pure scalar, const Vector3D& vec) {
            return vec * scalar;
        }

        Vector3D operator/(Pure scalar) const {
            if(scalar == 0) {
                throw NonsensicalException("Division by zero");
            }
            return *this * (1.0 / scalar);
        }
    };
}

#endif
