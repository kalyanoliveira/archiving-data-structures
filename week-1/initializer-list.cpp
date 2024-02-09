// Initializer lists in C++ have a purpose, but I just won't bother explaining
// them right now. Here's a
// [video](https://www.youtube.com/watch?v=1nfuYMXjZsA) if you are interested.

#include <iostream>
#include <string>

class Person {
    public:
        Person();
        Person(std::string n);

        std::string get_name() const;

        void change_name(const std::string n);

    private:
        std::string name;
};

Person::Person() {
    name = "0";
}

Person::Person(std::string n) {
    name = n;
}

std::string Person::get_name() const {
    return name;    
}

void Person::change_name(const std::string n) {
    name = n;
}

void print(Person p){
    std::cout << "This is a person with the name of " << p.get_name() << std::endl;
}

//class Car {
//    public:
//       Car();
//       Car(const Person &p);
//
//       Person get_owner() const;
//       std::string model_name() const;
//
//    private:
//       Person owner;
//       std::string model_name;
//};

int main(void) {

    return 0;
}
