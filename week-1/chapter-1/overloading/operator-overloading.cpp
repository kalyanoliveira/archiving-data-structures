// Just like there's `function-overloading.cpp`, there's also operator
// overloading. The compiler is smart enough to figure out what the types of
// variables are in an expression.

// ==HOWEVER== you can only overload operations for user defined types
// (classes, types imported from libraries, structs, etc), or enumerations.

// For instance, this would not work, because both an int and a double are
// primitive types.
// int operator+(const int &x, const double &y)
// {
//     return x + int(y);
// }

#include <iostream>
#include <string>

struct BankAccount {
    std::string owner;
    double balance;
};

double operator+(const BankAccount &f, const BankAccount &s) {
    return f.balance + s.balance;
}

int main(void) {
    BankAccount first_account = {"Kalyan", 1000.00};
    BankAccount second_account = {"Tarik", 1000.00};

    std::cout << "The total balance of the two accounts is: " <<
        first_account + second_account << std::endl;

    return 0;
}
