// Initializer lists in C++ have a purpose, but I just won't bother explaining
// them right now. Here's a
// [video](https://www.youtube.com/watch?v=1nfuYMXjZsA) if you are interested.

#include <iostream>
#include <string>

// Here, we define a class that **requires** a `string` argument for being
// constructed.
class Person {
    public:
        Person(std::string n);

        std::string get_name() const;

    private:
        std::string name;
};
Person::Person(std::string n) {
    std::cout << "Initializing Person of name " << n << std::endl;
    name = n;
}
std::string Person::get_name() const {
    return name;    
}
void print(Person p){
    std::cout << "This is a person with the name of " << p.get_name() << std::endl;
}

class Car {
    public:
        Car(std::string o_name = "UNKNOWN", std::string m_name = "UNKNOWN");

        Person get_owner() const;
        std::string get_model_name() const;

    private:
        Person owner;
        std::string model_name;
};

// // When we write this constructor, we run into a problem.
// // We need to construct this instance of `Car`, which has two data members:
// // 1. `owner`, of type `Person`
// // 2. `model_name`, of type `std::string`
// // Now, `model_name` is not the problem here. The problem is `owner`.
// // `owner` is an instance of the class `Person`, and a `Person` **requires** a
// // string to be constructed.
// Car::Car(std::string o_name, std::string m_name) {
//     // However, by the time we reach the body of this constructor function,
//     // `owner.Person(std::string n)` has already been called, and already
//     // generated an error because it is missing an argument.
//     model_name = m_name;
//     // Notice how these don't work:
//     owner(o_name); // I mean, what even is this?
//     owner = o_name;
//     // First of all, `owner` has already been created (and bugged out) at this 
//     // point. Second, we have not implemented the assignment `=` operator for
//     // the `Person` type.
// }

// Enter initializing lists! They help us fix this problem, and still maintain
// the `o_name` parameter in our `Car` constructor.
// The way it works is that you add a colon `:` after the parameter definition,
// and before the function's body.
Car::Car(std::string o_name, std::string m_name) 
    : owner(o_name) {
        model_name = m_name;
}

// // We could also do this:
// Car::Car(std::string o_name, std::string m_name) 
//     : owner(o_name), model_name(m_name) {
// }
// // Just note that you have to put the data members *in the same order as they
// // were defined inside the class.

Person Car::get_owner() const {
    return owner;
}

std::string Car::get_model_name() const {
    return model_name;
}

void print(const Car &c) {
    std::cout << "Car: " << std::endl << "Owner: ";
    print(c.get_owner());
    std::cout << "Model name: " << c.get_model_name() << std::endl;
}

int main(void) {
    Person p("Kalyan");
    print(p);

    Car c;
    print(c);

    Car camaro("Kalyan", "camaro");
    print(camaro);

    return 0;
}

// Granted, all of the problems shown here (and portrayed as being "fixed" by
// initializing lists) could be fixed in various other ways. This was just a
// scenario that I created to explain how initializing lists could be used.
