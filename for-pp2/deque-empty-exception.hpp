#ifndef DEQUE_EMPTY_EXCEPTION_H
#define DEQUE_EMPTY_EXCEPTION_H

#include <string>
#include <stdexcept>

class DequeEmpty : public std::runtime_error {
    public:
        DequeEmpty(const std::string &msg = "Deque is empty") :
            runtime_error (msg) {
        }
};

#endif
