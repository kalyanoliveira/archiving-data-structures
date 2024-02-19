#ifndef INVALID_INPUT_STRING_H
#define INVALID_INPUT_STRING_H

#include <string>
#include <stdexcept>

class InvalidInputString : public std::runtime_error {
    public:
        InvalidInputString(const std::string &msg = "Input string contains invalid notation.") :
            runtime_error (msg) {
        }
};

#endif
