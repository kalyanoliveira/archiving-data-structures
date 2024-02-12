// In protected inheritance, public fields of the base class become protected
// fields in the child class.

#include <iostream>

class Base {
    public:
        int this_becomes_protected_in_child();
};

int Base::this_becomes_protected_in_child() {
    return 7;
}

class Child : protected Base {
    // // Since `Child` inherents in a protected manner from `Base`, it's as if
    // // we had this:
    // protected:
    //     int this_becomes_protected_in_child();
};

class GrandChild : public Child {
    public:
        int this_calls_the_protected_function();
};

int GrandChild::this_calls_the_protected_function() {
    return this_becomes_protected_in_child();
}

int main(void) {
    GrandChild gc;

    std::cout << gc.this_calls_the_protected_function() << std::endl;

    // // This should not work:
    // std::cout << gc.this_becomes_protected_in_child() << std::endl;

    return 0;
}
