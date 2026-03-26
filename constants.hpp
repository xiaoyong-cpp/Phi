#ifndef PHI_CONSTANTS_HPP
#define PHI_CONSTANTS_HPP

#include "defines.hpp"
#include "scalars.hpp"

namespace phi {
    const Pure PI = 3.14159265358979323846;
    const Pure E = 2.71828182845904523536;
    const Acceleration gEarth = 9.81_m_s2;
    const Scalar G = (Long(1) * Long(1) * Force(1) * Mass(-1)) * (Pure)6.67438e-11;
}

#endif
