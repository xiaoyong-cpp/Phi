#include "../scalars.hpp"
#include "../defines.hpp"
#include <string>
#include <cmath>
#include <memory>

namespace phi {
    class Vector2D {
    public:
        std::shared_ptr<Scalar> x;
        std::shared_ptr<Scalar> y;

        Pure angle() {
            return atan2(y->value, x->value);
        }

        Pure length() {
            return sqrt(y->value * y->value + x->value * x->value);
        }

        Vector2D(std::shared_ptr<Scalar> __x, std::shared_ptr<Scalar> __y) {
            x = std::move(__x);
            y = std::move(__y);
        }        // Vector2D(make_unique<Long>(10), make_unique<Long>(20))
    };
}