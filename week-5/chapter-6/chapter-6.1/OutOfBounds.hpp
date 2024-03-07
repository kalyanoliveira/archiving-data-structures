#ifndef OUT_OF_BOUNDS_H
#define OUT_OF_BOUNDS_H

#include <stdexcept>
#include <string>

class OutOfBounds : public std::runtime_error {
    public:
        OutOfBounds(const std::string &msg = "Index is out of bounds") 
            : runtime_error(msg) { };
};

#endif
