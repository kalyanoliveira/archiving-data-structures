#include <iostream>
#include "NotationConverter.hpp"
#include <string>

int main(void) {
    NotationConverter nc;

    std::string s = nc.infixToPostfix("(((A + B) / (X + Y)) - R)");

    std::cout << s << std::endl;

    return 0;
}
