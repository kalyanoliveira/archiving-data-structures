// CPP provides a much more simple library for allocating memory.

#include <iostream>

int main(void)
{
    // Let's borrow some code from `structs.cpp`.
    enum Day {U, M, T, W, R, F, S} favorite_day_of_week;
    struct Person {
        std::string name;
        int age;
        bool alive;
        Day favorite_day_of_week;
    };

    // Creating a pointer to a Person.
    Person *p;

    // Here, we use the `new` operator to allocate some space in the heap for a
    // new `Person`.
    p = new Person;

    // The important aspect here is that `p` is a pointer, an address. Hence,
    // we must use the `->` operator.
    p->name = "Daquavious";
    p->age = 1000;
    p->alive = true;
    p->favorite_day_of_week = S;

    std::cout << "Hi, my name is " + p->name + ", I am " << p->age <<
        " years old, I am " << (!p->alive ? "not " : "") << "alive, "
        << "and I love day " << p->favorite_day_of_week << " of the week!"
        << std::endl;

    // Once we are done using our allocate chunk of heap memory, we can
    // deallocate it with `delete`:

    delete p;

    return 0;
}
