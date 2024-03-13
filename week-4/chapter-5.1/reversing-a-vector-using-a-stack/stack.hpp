#ifndef STACK_H
#define STACK_H

#include "ll.hpp"

class Stack {
    public:
        void push(const int v);
        int pop();
        int peek() const;

    private:
        LinkedList ll;
};

#endif
