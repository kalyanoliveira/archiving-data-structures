#ifndef DEQUE_H
#define DEQUE_H

#include "dll.hpp"
#include "deque-empty-exception.hpp"
#include <string>

class Deque {
    public:
        Deque();

        // We don't need a destructor, since Deque itself does not allocate.
        // ~Deque();
        
        bool empty() const;

        // To use a deque like a stack, we use the front functions.
        // To use a deque like a queue, we push to the back, and pop the front. 
        
        void push_to_front(const std::string &c);
        void push_to_back(const std::string &c);

        std::string pop_front();
        std::string pop_back();

        std::string peek_front() const;
        std::string peek_back() const;

    private:
        DLL dll;
        int n;
};

#endif
