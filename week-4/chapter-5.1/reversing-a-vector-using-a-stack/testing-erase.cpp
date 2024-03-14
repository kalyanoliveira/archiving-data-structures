#include <iostream>
#include "vector.hpp"

int main(void) {
    Vector v;
    
    v.insert(0, 1);
    v.insert(1, 2);
    v.insert(2, 3);
    v.insert(3, 4);
    v.insert(4, 5);
    v.insert(5, 6);
    v.print();

    v.erase(0);
    v.print();

    return 0;
}
