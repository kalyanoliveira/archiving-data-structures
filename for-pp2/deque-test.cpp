#include <iostream>
#include "deque.hpp"

int main(void) {
    Deque d; 

    d.push_to_back("a");
    d.push_to_back("b");
    d.push_to_back("c");
    d.push_to_back("d");
    d.push_to_back("e");
    d.push_to_back("f");

    d.push_to_front("a");
    d.push_to_front("b");
    d.push_to_front("c");
    d.push_to_front("d");
    d.push_to_front("e");
    d.push_to_front("f");


    std::cout << d.pop_back() << std::endl;

    std::cout << d.pop_back() << std::endl;

    std::cout << d.pop_back() << std::endl;
    std::cout << d.pop_back() << std::endl;
    std::cout << d.pop_back() << std::endl;
    std::cout << d.pop_back() << std::endl;
    std::cout << " - - - " << std::endl;
    std::cout << d.pop_front() << std::endl;
    std::cout << d.pop_front() << std::endl;
    std::cout << d.pop_front() << std::endl;
    std::cout << d.pop_front() << std::endl;
    std::cout << d.pop_front() << std::endl;
    std::cout << d.pop_front() << std::endl;


    return 0;
}
