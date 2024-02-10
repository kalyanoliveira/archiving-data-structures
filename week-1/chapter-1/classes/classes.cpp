// You know what classes are.
// But they are so much more complicated in C++ than Python bro.

#include <iostream>

class Counter {
    // Every class has a private part and public part.
    // Private "members" are not accessible from outside the class. Public ones
    // are.
    public:
        // Every class has a "constructor function," which takes the same name
        // as the class itself.
        // This "constructor function" is called when we instantiate the class.
        Counter();

        // We can then define whatever we want.
        
        // Getters usually have the word `const` in the end of their
        // signatures.
        int get_count() const;

        void increase_count(const int n);

    private:
        // Here, I'll be defining my `count` variable. It should located in the
        // private section because I don't want anyone else (besides the class
        // itself) looking at it.
        int count;
};

// Now, we'll introduce a new operator; it's called the "scope resoulution"
// operator, and it looks like this `::`.
// This operator essentially allows us to say "call this attribute/function
// *from* this namespace/class."
// And we have seen it before. Consider `std::cout`. Here, we are saying "call
// `cout`, which is part of the `std` "scope". This is what the `::` are doing:
// they are increasing the "resolution" of our "scope".

// Methods are defined using the "scope resolution" operator. For our `Counter`
// class, we'll be appending `Counter::` to the name of our functions in their
// signatures:

Counter::Counter() {
    count = 0;
}

int Counter::get_count() const {
    return count;
}

void Counter::increase_count(const int n) {
    count += n;
}

void print(const Counter &c) {
    std::cout << "Counter: " << c.get_count() << std::endl;
}


int main(void) {
    // We can create instance of a class by simply creating a variables with
    // the type of that class.
    Counter c;

    // Let's test some operations!
    print(c);
    c.increase_count(7);
    print(c);
    c.increase_count(-7);
    print(c);

    return 0;
}
