// CPP actually defines a `string` type for us, under `std`. It's defined under
// this header:
#include <string>

#include <iostream>

int main(void)
{
    // Simple "hello world."
    std::string h = "Hello";
    std::string w = ", world!";
    std::cout << h + w << std::endl;

    // A greeting.
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;
    std::cout << h + ", " + name << std::endl;

    // You can also get the size of a string:
    int index = h.size();

    std::cout << h[index - 1] << std::endl;

    return 0;
}
