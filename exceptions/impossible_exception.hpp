#ifndef PHI_EXCEPTIONS_IMPOSSIBLE_EXCEPTION_HPP
#define PHI_EXCEPTIONS_IMPOSSIBLE_EXCEPTION_HPP

#include "base.hpp"
#include <string>

namespace phi {
    class ImpossibleException {
    public:
        ImpossibleException(std::string msg) : message("Impossible operation: " + msg) {}
    };
}

#endif