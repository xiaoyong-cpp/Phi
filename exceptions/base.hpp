#ifndef PHI_EXCEPTIONS_BASE_HPP
#define PHI_EXCEPTIONS_BASE_HPP

#include <exception>
#include <string>

namespace phi {
    class Exception : public std::exception {
    private:
        std::string message;
    public:
        Exception(const std::string& message) : message(message) {}
        const char* what() const noexcept override {
            return message.c_str();
        }
    };
}

#endif