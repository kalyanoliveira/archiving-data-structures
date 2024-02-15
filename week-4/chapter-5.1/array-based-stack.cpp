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

        void pop();

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

void Stack::push(const int &v) {
    // If we have reached the capacity, let's abort and simply return early.
    if (number_of_elements == capacity) {
        std::cout << "Push: Stack is full" << std::endl;
        return;
    }
    // This means that our stack has not reached capacity, and that we can thus
    // add another element.

    // Add the new element to the array.
    elements[number_of_elements] = v;

    // Increase the element count.
    number_of_elements++;

    return;
}

void Stack::pop() {
    // If the stack is empty, there is nothing to pop.
    // So let's just error that.
    if (is_empty()) {
        std::cout << "Pop: Stack is empty" << std::endl;
        return;
    }

    // Decrease the element count.
    number_of_elements--;
}

bool Stack::is_empty() const {
    return number_of_elements == 0;
}

int Stack::size() const {
    return number_of_elements;
}

int Stack::peek() const {
    if (is_empty()) {
        std::cout << "Peek: Stack is empty, returning -1" << std::endl;
        return -1;
    }

    return elements[number_of_elements - 1];
}

int main(void) {
    Stack s(10);

    s.push(7);
    s.push(8);
    s.push(9);
    std::cout << s.peek() << std::endl;

    s.pop();
    s.pop();
    std::cout << s.peek() << std::endl;

    s.pop();
    std::cout << s.peek() << std::endl;

    return 0;
}
