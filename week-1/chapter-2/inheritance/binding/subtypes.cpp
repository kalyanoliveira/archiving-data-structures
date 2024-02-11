// In this file, we are going to demonstrate the concept of "subtypes."

#include <iostream>

// We are going to first need some inheritance.
class Base {
    public:
        Base();

        void print();

    private:
        int base_value;
};

Base::Base() {
    base_value = 7;
}

void Base::print() {
    std::cout << "Base: " << base_value << std::endl;
}

class Child : public Base {
    public:
        Child();

        void print();

    private: 
        int child_value;
};

Child::Child() {
    child_value = 11;
}

void Child::print() {
    std::cout << "Child: " << child_value << std::endl;
}


int main(void) {
    // What is essentially happening here is that a child class is said to a
    // `subtype` of the base class. Because a child class is a `subtype` of a
    // base class, the child class type may be used wherever we use the base
    // class type.
    // Here's an example of this with arrays:
   
    // An array of 10 pointers to `Base` objects.
    Base *a[10];

    // Since `Child` is a "subtype" of `Base`, we can populate `a` with
    // pointers to both `Base` and `Child` objects:
    a[0] = new Base;
    a[1] = new Child;

    std::cout << "Program works" << std::endl;

    return 0;    
}
