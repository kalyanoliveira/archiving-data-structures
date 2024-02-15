// A stack is dead simple: you have push, pop, and top (which just returns the
// value of the top element) functions.

// Optionally, you may also have an is_empty() function and a size() function.

// Here, we'll do a dynamic array-based stack.

#include <iostream>

class Stack {
    public:
        // We need to specify the capacity of a Stack when we construct it.
        Stack(const int &c);

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

Stack::Stack(const int &c) {
    capacity = c; 
    elements = new int[c];
    number_of_elements = 0;
}

Stack::~Stack() {
    delete [] elements;
}

int main(void) {
    Stack s(10);

    return 0;
}
