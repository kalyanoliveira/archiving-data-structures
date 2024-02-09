#include <iostream>

int main(void)
{
    // CPP also provides something called static casting, which is more verbose
    // but is preferred over normal C-style casting and functional casting as
    // to alert the programmer about potential problems during type conversion.
   
    int n0 = 10;
    double n1 = static_cast<double>(n0);

    std::cout << n1 << std::endl;

    return 0;
}
