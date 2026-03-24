#ifndef PHI_EXCEPTIONS_NONSENSICAL_EXCEPTION_HPP
#define PHI_EXCEPTIONS_NONSENSICAL_EXCEPTION_HPP

#include "base.hpp"
#include <string>

namespace phi {
    class NonsensicalException : public Exception {
    public:
        NonsensicalException(const std::string& message) : Exception("Nonsensical operation: " + message) {}
    };
}



#endif