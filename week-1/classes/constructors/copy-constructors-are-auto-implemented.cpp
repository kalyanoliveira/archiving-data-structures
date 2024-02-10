// I'm not sure if this applies to older versions of g++, but copy constructors
// are auto-generated if you do not specify them.
// This file demonstrates that.

#include <iostream>

class Something {
    public:
        Something();
        Something(int v);

        int get_value() const;
    private:
        int value;
};

Something::Something() {
    value = 0;
}

Something::Something(int v) {
    value = v;
}

int Something::get_value() const {
    return value;
}

void print(const Something &s) {
    std::cout << "Something: " << s.get_value() << std::endl;
}

int main(void) {
    Something s0(7);
    print(s0);

    // Now, here are two examples of how you can use the auto-created copy
    // constructors:

    // Copy constructor auto implemented!
    Something s1(s0);
    print(s1);

    // This is a combination of the fact that copy constructors are auto
    // implemented, plus some compiler magic:
    Something s2 = s2;
    print(s2);

    return 0;
}
