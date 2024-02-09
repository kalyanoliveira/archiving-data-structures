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

    // Copy constructor auto implemented!
    Something s1(s0);
    Something s2(s0);

    print(s0);
    print(s1);
    print(s2);

    return 0;
}
