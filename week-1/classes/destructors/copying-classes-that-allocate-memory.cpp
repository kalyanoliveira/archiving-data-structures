// Whenever we create a class that allocates chunks of our heap memory, we can
// always fall into some bad errors. Specifically, I am talking about errors
// that arise whenever we create a new instance of a class (that allocates
// memory) based on an existing instance of it.

#include <iostream>

// We are going to define a very simple class here; that allocates space for an
// integer.
class Something {
    public:
        Something(int x);
        ~Something();

        // See the below to understand these two functions:
        Something(const Something &s);
        Something &operator=(const Something &s);

        int *get_integer_pointer() const;

    private:
        int *integer_pointer;
};

Something::Something(int x) {
    integer_pointer = new int(x);
}

Something::~Something() {
    delete integer_pointer;
}

int *Something::get_integer_pointer() const { 
    return integer_pointer;
}

void print(const Something &s) {
    std::cout << *(s.get_integer_pointer()) << std::endl;
}

// The idea here is prevent shallow copies by doing two things:
// 1. Writing a copy constructor, instead of using the default,
//    compiler-generated one.
// 2. Overloading the assignment operator for the `Something` class.

// 1. Writing a copy constructor.
Something::Something(const Something &s) {
    integer_pointer = new int(*s.get_integer_pointer());
}

// 2. Overloading the assignment operator for the `Something` class.
// There are so many things that are new here:
// - Notice the return type, which is `Something &`. This is useful for when we
//   want to chain assignment operations, as in `a=b=c` because the parameter of
//   `operator=` is `Something &`.
// - `this` simply refers to the address of the instance to which we are
//   assigning to.
// - `s` is the right-hand side of the assignment operation.
// - Also notice that we have to specify the `Something::` scope.
Something &Something::operator=(const Something &s) {
    // If we are assigning an instance to itself, let's just return the
    // instance itself.
    if (this == &s) return *this;

    // If we are assigning this instance some legitimate "other" instance, we
    // have to prevent shallow copies (i.e., make "hard" copies):
    *(this->integer_pointer) = *s.get_integer_pointer();

    return *this;
}

int main(void) {
    Something s0(7); 
    print(s0);
    
    // Remember: this should work because
    // `copy-constructors-are-auto-implemented.cpp`:
    // Two ways to copy:
    // 1.
    Something s1(s0);
    print(s1);
    // 2.
    Something s2 = s0;
    print(s2);

    // Assignment should also work errorlessly, now that we prevented shallow
    // copies.
    s0 = s2;
    print(s0);

    // After we return this `main` function, destructors are going to get
    // called. And we should be all good, because we prevented shallow copies
    // from absolutely destroying our lives at this point.
    return 0;
}
