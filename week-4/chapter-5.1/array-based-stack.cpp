// A stack is dead simple: you have push, pop, and top (which just returns the
// value of the top element) functions.

// Optionally, you may also have an is_empty() function and a size() function.

// Here, we'll do a dynamic array-based stack.

#include <iostream>

class Stack {
    public:
        Stack();
        // We a need destructor, since we are allocating space in memory.
        ~Stack();

        int top();
        
        void push(const int &v);

        void pop(const int &v);

    private:
        int *elements;
        int capacity;
        int number_of_elements;
};

int main(void) {
    return 0;
}
