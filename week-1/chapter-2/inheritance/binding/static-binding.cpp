// What are going to be showing here is an apparently anomalous behavior which
// we call "static binding."

#include <iostream>

// Let's borrow some of the code from `subtypes.cpp`.
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
    Base *a[10];

    // Remember, this works because `Child` is a subtype of `Base`.
    a[0] = new Base;
    a[1] = new Child;
   
    // We can call the `print` method of `Base` just fine.
    a[0]->print();

    // However, here's the crazy part: calling the `print` method of `Child`
    // actually calls the `print` of `Base`.
    a[1]->print();

    // The reason for this is, of course, "static binding."
    
    // I'm not quite sure what "binding" means just yet, but focus on the
    // "static" part: it gives you a clue about what's actually happening here.
    
    // The compiler has to decide which method to call in `a[1]->print()`. This
    // process is "static" because it occurs during compile-time (if it were
    // "dynamic," it would occur during runtime).
    
    // The compile-time decision made by the compiler is to use the "declared
    // type" `a[1]`.
    // `a[1]` is declared to be a pointer to a `Person` object. Hence, calling
    // `print()` will call the `Person` object's `print` method.

    return 0;    
}
