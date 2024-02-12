// In private inheritance, public and protected fields of the base class become
// private fields in the child class.

#include <iostream>

class Base {
    public:
        Base();
        
        int base_public_value;

    private:
        int base_private_value;

    protected:
        int base_protected_value;
};

Base::Base() {  
    base_public_value = 7;
    base_private_value = 11;
    base_protected_value = 15;
}

class Child : private Base {
    // // We could say that we have something like this:
    // private:
        // int base_public_value;
        // int base_protected_value;
    public:
        int get_base_public_value() const;
        int get_base_protected_value() const;
};

int Child::get_base_public_value() const {
    return base_public_value;
}

int Child::get_base_protected_value() const {
    return base_protected_value;
}

class GrandChild : public Child {
};

int main(void) {
    // Let's see what kind of access we have here:
    Base b;
    Child c;
    GrandChild gc;

    // Testing `b` functionality.
    std::cout << b.base_public_value << std::endl;
    // // Illegal.
    // std::cout << b.base_private_value << std::endl;
    // std::cout << b.base_protected_value << std::endl;
    
    // Testing `c` functionality.
    std::cout << c.get_base_public_value() << std::endl;
    std::cout << c.get_base_protected_value() << std::endl;
    // // Illegal
    // std::cout << c.base_public_value << std::endl;
    // std::cout << c.base_protected_value << std::endl;
    
    // Testing `gc` functionality.
    // Poor grandchild; has not inherited any fortunes from his Grandfather
    // yet!
    std::cout << gc.get_base_public_value() << std::endl;
    std::cout << gc.get_base_protected_value() << std::endl;
    // // Of course, this is illegal: we are dealing with members that are
    // // private to `Child`.
    // std::cout << gc.base_public_value << std::endl;
    // std::cout << gc.base_protected_value << std::endl;

    return 0;
}
