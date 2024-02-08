// Pointers can point to nothing.
// There are two ways to do this: with a `0`, or a `NULL`.

// However, a `NULL` requires this header, which is the CPP standard library:
#include <cstdlib>

#include <iostream>

int main(void)
{
    int number = 7;
    
    // "Points to nothing."
    int *p = 0;
    int *q = NULL;

    std::cout << p << std::endl;
    std::cout << q << std::endl;

    p = &number;
    q = &number;

    std::cout << *p << std::endl;
    std::cout << *q << std::endl;

    return 0;
}
