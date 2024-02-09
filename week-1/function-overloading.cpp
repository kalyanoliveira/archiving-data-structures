// The concept here is simple: functions can have the same name, but different
// parameters. The compiler is smart enough to figure out what function should
// be used where.

#include <iostream>

void print(int n)
{
    std::cout << "this is an integer: " << n << std::endl;
}

void print(double n)
{
    std::cout << "this is an double: " << n << std::endl;
}

int main(void)
{
    int n = 7;
    double x = 7.7;

    print(n);
    print(x);

    return 0;
}
