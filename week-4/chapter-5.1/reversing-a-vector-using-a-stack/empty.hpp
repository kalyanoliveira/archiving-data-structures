#ifndef EMPTY_H
#define EMPTY_H

#include <stdexcept>
#include <string>
    
class Empty : public std::runtime_error {
    public:
        Empty(const std::string &msg = "Empty exception") : 
            runtime_error(msg) {
        }
};

#endif
