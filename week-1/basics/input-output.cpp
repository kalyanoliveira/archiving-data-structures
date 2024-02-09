// To use input output, you must include this header:

#include <iostream>

int main(void)
{
    // We call, from the `std` scope, `cout`, and use the `<<` operator (which
    // we can just call the "output operator") to pass stuff to stdout.
    std::cout << "Hello, world!" <<

    // Then, we can use `endl` from `std` to output a newline character.
    std::endl;

    // Now, we are going to demonstrate input output with `cin`. We use the
    // "input operator" `>>`.
    std::cout << "Input a number: ";
    int number;
    std::cin >> number;

    // Let's display that.
    std::cout << "Your number was: " << number << std::endl;

    return 0;
}
