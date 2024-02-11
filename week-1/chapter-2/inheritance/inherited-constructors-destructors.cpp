// When dealing with inheritance, we must call the constructors of base classes
// before the constructors of children classes by using an initializer list.
//
// Destructors are called in reverse order: first the destructors of
// children classes, followed by the destructors of base classes.
//
// However, we don't actually need to call the destructors of base classes.
// That is done automatically.

#include <iostream>

class Base {
    public:
        Base();
        ~Base();

        int *get_value0() const;

    private:
        int *value0;
};

Base::Base() {
    value0 = new int(7);
}

Base::~Base () {
    delete value0;
}   

int *Base::get_value0() const {
    return value0;
}
    
class Child : public Base {
    public:
        Child();
        ~Child();

        int *get_value1() const;

    private:
        int *value1;
};

// Uses an initializer list of call the base constructor first.
Child::Child() 
    : Base() {
        value1 = new int(11);
}

// Here, we don't need to explictly call the `~Base` destructor. `~Child` does
// that automatically.
Child::~Child() {
    delete value1;
}

int *Child::get_value1() const {
    return value1;
}

int main(void) {
    Child c;

    std::cout << *c.get_value0() << " " << *c.get_value1() << std::endl;

    return 0;
}
