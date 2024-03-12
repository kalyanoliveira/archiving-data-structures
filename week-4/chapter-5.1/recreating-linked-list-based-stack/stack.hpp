#ifndef STACK_H
#define STACK_H

#include "ll.hpp"

class Stack {
    public:
        int peek() const;
        void push(const int v);
        int pop();

    private:
        LinkedList ll;
};

#endif
