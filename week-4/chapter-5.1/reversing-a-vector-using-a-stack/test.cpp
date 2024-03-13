#include <iostream>

#include "ll.hpp"
#include "stack.hpp"
#include "empty.hpp"
#include "vector.hpp"

int main(void) {
    Vector v;

    // Put some stuff into the vector.
    v.insert(0, 1);
    v.insert(1, 2);
    v.insert(2, 3);

    // So that we don't have to perform many functions calls.
    int len = v.size();

    // Show the initial state.
    for (int i = 0; i < len; i++) std::cout << v.at(i) << " ";
    std::cout << std::endl;

    // Push the elements from the vector into the stack, starting from the beginning.
    Stack s;
    for (int i = 0; i < len; i++) {
        s.push(v.at(i));
    }

    // Pop the elements from the stack, setting them into the vector.
    for (int i = 0; i < len; i++) {
        v.set(i, s.pop());
    }

    // Show the reversed:
    for (int i = 0; i < len; i++) std::cout << v.at(i) << " ";
    std::cout << std::endl;

    return 0;
}
