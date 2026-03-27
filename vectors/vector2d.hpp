#ifndef PHI_VECTOR2D_HPP
#define PHI_VECTOR2D_HPP

#include "../scalars.hpp"
#include "../defines.hpp"
#include "../exceptions.hpp"
#include <string>
#include <cmath>

namespace phi {
    class Vector2D {
    public:
        Scalar* x;
        Scalar* y;

        Pure angle() const {
            return atan2(y->value, x->value);
        }

        Pure length() const {
            return sqrt(y->value * y->value + x->value * x->value);
        }

        Vector2D(Scalar* __x, Scalar* __y) {
            x = __x;
            y = __y;
        }

        Vector2D(Scalar& __x, Scalar& __y) {
            x = &__x;
            y = &__y;
        }

        Vector2D operator/(const Scalar& scalar) const {
            if(!x || !y || scalar.value == 0) {
                throw NonsensicalException("Division by zero");
            }
            return Vector2D(&(*x / scalar), &(*y / scalar));
        }

        Vector2D(const Vector2D& other)
            : x(other.x ? other.x->clone() : nullptr),
              y(other.y ? other.y->clone() : nullptr) {}

        Vector2D(Vector2D&& other) noexcept = default;

        Vector2D& operator=(const Vector2D& other) {
            if(this != &other) {
                x = other.x ? other.x->clone() : nullptr;
                y = other.y ? other.y->clone() : nullptr;
            }
            return *this;
        }

        Vector2D& operator=(Vector2D&& other) noexcept = default;

        Vector2D operator+(const Vector2D& other) const {
            if(!x || !y || !other.x || !other.y) {
                throw NonsensicalException("Cannot add vectors with null components");
            }
            if(!x->sameDimensions(*other.x)) {
                throw NonsensicalException("Addition of vectors with different X dimensions between " + x->name + " and " + other.x->name);
            }
            if(!y->sameDimensions(*other.y)) {
                throw NonsensicalException("Addition of vectors with different Y dimensions between " + y->name + " and " + other.y->name);
            }
            return Vector2D(x->add(*other.x), y->add(*other.y));
        }

        Vector2D operator-() const {
            if(!x || !y) {
                throw NonsensicalException("Cannot negate vector with null components");
            }
            return Vector2D(x->negate(), y->negate());
        }

        Vector2D operator-(const Vector2D& other) const {
            return *this + (-other);
        }

        Vector2D operator*(Pure scalar) const {
            if(!x || !y) {
                throw NonsensicalException("Cannot multiply vector with null components");
            }
            return Vector2D(x->multiply(scalar), y->multiply(scalar));
        }

        friend Vector2D operator*(Pure scalar, const Vector2D& vec) {
            return vec * scalar;
        }

        Vector2D operator*(const Scalar& scalar) const {
            return Vector2D(&(*x * scalar), &(*y * scalar));
        }

        Vector2D operator/(Pure scalar) const {
            if(scalar == 0) {
                throw NonsensicalException("Division by zero");
            }
            return *this * (1.0 / scalar);
        }
    };
}

#endif
