#include <iostream>
#include "stack.hpp"

int main(void) {
    std::cout << "running" << std::endl;

    Stack s;

    s.push(5);
    s.push(6);
    s.push(7);

    std::cout << s.peek() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    s.push(10);
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;

    return 0;
}
