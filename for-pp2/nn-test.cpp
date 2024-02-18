#include <iostream>
#include "NotationConverter.hpp"
#include <string>

int main(void) {
    NotationConverter nc;

    std::string s = nc.postfixToInfix("ab+");

    std::cout << s << std::endl;

    return 0;
}
