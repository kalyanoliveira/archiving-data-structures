#ifndef DEQUE_H
#define DEQUE_H

#include "dll.hpp"
#include "deque-empty-exception.hpp"

class Deque {
    public:
        Deque();

        // We don't need a destructor, since Deque itself does not allocate.
        // ~Deque();
        
        bool empty() const;

        // To use a deque like a stack, we use the front functions.
        // To use a deque like a queue, we push to the back, and pop the front. 
        
        void push_to_front(const char &c);
        void push_to_back(const char &c);

        char pop_front();
        char pop_back();

        char peek_front() const;
        char peek_back() const;

    private:
        DLL dll;
        int n;
};

#endif
