// Remember we had static casting? Well, C++ also has dynamic casting.
// It has a lot to do with polymorphism, virtual member functions, and dynamic
// binding.

#include <iostream>

// Before anyting, I need to get some inheritance code here:

class Base {
    public:
        Base();

        virtual void print();

    private:
        int base_value;

};

Base::Base() {
    base_value = 7;
}

void Base::print() {
    std::cout << base_value << std::endl;
}

class Child : public Base {
    public:
        Child();

        virtual void print();

        int only_child_has_this_function();

    private:
        int child_value;
};

Child::Child() {
    child_value = 11;
}

void Child::print() {
    std::cout << child_value << std::endl;
}

int Child::only_child_has_this_function() {
    return 15;
}

int main(void) {
    // Let's create an array of pointers to the declared type `Base`:
    Base *a[2];

    // Let's assign some stuff to that array:
    a[0] = new Base;
    // Remember, this works because of "subtypes."
    a[1] = new Child;

    // We've already set up dynamic binding above by the usage of the `virtual`
    // keyword.
    a[0]->print();
    a[1]->print();

    // // However, we know that this statement would be illegal because only
    // // `Child` has the member function `only_child_has_this_function()`.
    // // We could try adding `virtual` to `only_child_has_this_function(), but
    // // it would be futile: it would not change the fact that `Base` does not
    // // have `only_child_has_this_function()`, and `Base` is the "declared
    // // type" of `a[0]`
    // a[0]->only_child_has_this_function()
    
    // What we can do, however, is do a "dynamic cast." A dynamic cast is done
    // during run-time and **to polymorphic objects** (i.e. objects that have
    // at least one virtual method).
    std::cout << (dynamic_cast<Child *>(a[0]))->only_child_has_this_function()
        << std::endl;

    // We have to worry about one fact, though: **a dynamic cast can fail** (as
    // in the case of a dynamic cast from a pointer to an instance of `Base` to
    // a pointer to an instance of `Child`). In such instances, we get NULL
    // pointer back.

    return 0;
}
