// Mostly just doing this because I need to remember how to define and
// initialize structs lol.

#include <iostream>
#include <string>

int main(void)
{
    // You should really not be defining structs only inside main.
    // Unless you have a very good reason for it.
    // I have one: I'm lazy.
    struct Person {std::string name; int age; bool alive;};

    Person someone = {"Daquavious", 1000, true};

    std::cout << "Hi, my name is " + someone.name + ", I am " << 
        someone.age << " years old, and I am " << 
        (!someone.alive ? "not " : "") << "alive." << std::endl;

    return 0;
}
