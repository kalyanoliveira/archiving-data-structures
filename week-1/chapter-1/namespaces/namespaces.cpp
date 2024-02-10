#include <iostream>

// You can define namespaces during compile time.
namespace first {
    bool condition = true;
}

// Using statements are also done during compile time. There may be conflict
// amongst namespaces!.
using namespace first;

int main(void)
{
    if (condition) {
        std::cout << "The condition is true" << std::endl;
    } else {
        std::cout << "The condition is true" << std::endl;
    }

    return 0;
}
