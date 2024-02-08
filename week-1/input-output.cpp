// To use input output, you must include this header:

#include <iostream>

int main(void)
{
    // We call, from the `std` scope, `cout`, and use the `<<` operator (which
    // we can just call the "output operator") to pass stuff to stdout.
    std::cout << "Hello, world!" <<

    // Then, we can use `endl` from `std` to output a newline character.
    std::endl;

    return 0;
}
