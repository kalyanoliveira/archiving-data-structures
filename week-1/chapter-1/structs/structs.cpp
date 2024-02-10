// Mostly just doing this because I need to remember how to define and
// initialize structs lol.

#include <iostream>
#include <string>

int main(void)
{
    // We are going to be creating a `Person` struct, and people like days of
    // the week. Hence, an enum!
    enum Day {U, M, T, W, R, F, S} favorite_day_of_week;

    // You should really not be defining structs only inside main.
    // Unless you have a very good reason for it.
    // I have one: I'm lazy.
    struct Person {
        std::string name;
        int age;
        bool alive;
        Day favorite_day_of_week;
    };

    Person someone = {"Daquavious", 1000, true, S};

    std::cout << "Hi, my name is " + someone.name + ", I am " << someone.age <<
        " years old, I am " << (!someone.alive ? "not " : "") << "alive, "
        << "and I love day " << someone.favorite_day_of_week << " of the week!"
        << std::endl;

    return 0;
}
