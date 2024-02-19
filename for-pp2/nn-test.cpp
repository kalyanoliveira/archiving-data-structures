#include <iostream>
#include "NotationConverter.hpp"
#include <string>
#include "invalid-input-string-exception.hpp"

int main(void) {
    NotationConverter nc;

    std::string s;

    s = "(a + b)";
    std::cout << nc.infixToPostfix(s) << std::endl;
    std::cout << nc.infixToPrefix(s) << std::endl;

    s = "ab+";
    std::cout << nc.postfixToInfix(s) << std::endl;
    std::cout << nc.postfixToPrefix(s) << std::endl;

    s = "+ab";
    std::cout << nc.prefixToInfix(s) << std::endl;
    std::cout << nc.prefixToPostfix(s) << std::endl;

    // This should throw.
    s = "lkajsdf:";
    try {
        std::cout << nc.infixToPostfix(s) << std::endl;
    } catch (InvalidInputString &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
