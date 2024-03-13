#ifndef INDEX_EXCEPTION_H
#define INDEX_EXCEPTION_H

#include <string>
#include <stdexcept>

class IndexException : public std::runtime_error {
    public:
        IndexException (const std::string &msg) :
            std::runtime_error(msg) {
        }
};

#endif
