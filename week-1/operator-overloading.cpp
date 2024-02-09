// Just like there's `function-overloading.cpp`, there's also operator
// overloading. The compiler is smart enough to figure out what the types of
// variables are in an expression.

#include <iostream>

int operator+(const int &x, const double &y)
{
    return x + int(y);
}

double operator+(const double &x, const int &y)
{
    return x + double(y);
}

int main(void)
{
    int n0 = 7;
    double n1 = 7.7;

    // Here, we get different results because of our operator overloading (and
    // not a compile-time error)>
    std::cout << n0 + n1 << std::endl;
    std::cout << n1 + n0 << std::endl;

    return 0;
}
