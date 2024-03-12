#ifndef EMTPY_EXCEPTION_H
#define EMTPY_EXCEPTION_H

#include <stdexcept>
#include <string>

class EmptyException : public std::runtime_error {
    public:
        EmptyException(const std::string &msg = "Something is empty") :
            runtime_error (msg) {
        }
};

#endif
