// A stack is dead simple: you have push, pop, and peek functions.

// Optionally, you may also have an is_empty() function and a size() function.

// Here, we'll do a dynamic array-based stack.

#include <iostream>

class Stack {
    public:
        // We need to specify the capacity of a Stack when we construct it.
        Stack(const int &c);

        // We a need destructor, since we are allocating space in memory.
        ~Stack();

        int peek() const;
        
        void push(const int &v);

        void pop(const int &v);

        bool is_empty() const;

        int size() const;

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

bool Stack::is_empty() const {
    return number_of_elements == 0;
}

int Stack::size() const {
    return number_of_elements;
}

int Stack::peek() const {
    if (is_empty()) {
        std::cout << "Stack is empty, returning -1";
        return -1;
    }

    return elements[number_of_elements - 1];
}

int main(void) {
    Stack s(10);

    return 0;
}
