#include <iostream>
#include "NotationConverter.hpp"
#include <string>

int main(void) {
    NotationConverter nc;

    std::string s = nc.postfixToPrefix("X Y + A B + *");

    std::cout << s << std::endl;

    return 0;
}
