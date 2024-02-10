// We call allow classes/functions to look into private members of (another)
// class by making them (the classes/functions) friends with that (other)
// class.

#include <iostream>

class Something {
    public:
        Something();

    private:
        int value;

        // We can give `OtherSomething` access to the `value` data member by
        // making it a friend.
        friend class OtherSomething;

        // We can also do the same with this function:
        friend int special_access_function(Something s);
};


Something::Something() {
    value = 0; 
}

class OtherSomething {
    public:
        int get_the_private_member(Something s);
};

int OtherSomething::get_the_private_member(Something s) {
    return s.value;
}

int special_access_function(Something s) {
    return s.value;
}

int main(void) {

    Something s;

    OtherSomething os;

    std::cout << os.get_the_private_member(s) << std::endl;

    std::cout << special_access_function(s) << std::endl;
    
    return 0;
}
