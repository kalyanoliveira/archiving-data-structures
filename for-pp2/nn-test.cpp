#include <iostream>
#include "NotationConverter.hpp"
#include <string>

std::string remove_spaces_from_string(std::string &s);

int main(void) {
    NotationConverter nc;

    std::string something = " asdf asdf a d ds fsd f     sd1 ";        

    something = remove_spaces_from_string(something);

    std::cout << something << std::endl;


    return 0;
}
