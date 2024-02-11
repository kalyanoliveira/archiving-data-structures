// We've already seen `static-binding.cpp`. Now, I'll show dynamic typing.
#include <iostream>

// Let's just get the inheritance related code that we had from before in
// `static-binding.cpp`.
class Base {
    public:
        Base();

        // By adding `virtual`, we are essentially saying that this function
        // should use dynamic binding.
        virtual void print();

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

        // By adding `virtual`, we are essentially saying that this function
        // should use dynamic binding.
        virtual void print();

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
    
    Base *a[2];

    a[0] = new Base;
    a[1] = new Child;

    // Remember: when we do the following operations, C++ has to decide which
    // method to call.
    a[0]->print();
    a[1]->print();

    // By adding the `virtual` keyword to both `Base::print()` and
    // `Child::print()`, we essentially told the compiler to make this decision
    // *during runtime*, and to use the contents of the actual objects (rather
    // than just their declared type) to make the decision of "which method to
    // call."
    
    // Which is why we get a call from `Base::print()` from the first line, and
    // a call from `Child::print()` from the second line.

    return 0;
}

