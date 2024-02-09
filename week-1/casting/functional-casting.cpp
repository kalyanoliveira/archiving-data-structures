#include <iostream>

int main(void)
{
    // In addition to normal C-style type casting, CPP also introduces
    // functional casting.
    int n0 = 10;
    double n1 = double(n0);

    std::cout << n1 << std::endl;

    return 0;
}
