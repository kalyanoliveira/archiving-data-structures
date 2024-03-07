#include <iostream>
#include "ArrayBasedVectorNoGrow.hpp"

int main(void){
    int c = 7;
    Vector v(c);

    v.insert(0, 0);
    v.insert(1, 1);
    v.insert(2, 2);
    v.insert(3, 3);
    v.insert(4, 4);
    v.insert(5, 5);
    v.insert(6, 6);

    v.erase(0);

    std::cout << v.size() << std::endl;

    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << std::endl;
    }

    return 0;
}
