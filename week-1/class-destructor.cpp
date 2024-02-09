// Classes can also have de-structors.
// By using destructors, we can give memory back to the system when we are done
// using it for classes.

#include <iostream>

// Let's create a Vector class!:
class Vec {
    public:
        Vec(int l);
        // Simple stuff: just add a tilde `~` to characterize a destructor function.
        ~Vec();

        int *get() const;
        int get_length() const;

        // You could add more stuff here.
        // But I won't.

    private:
        int *array;
        int length;
};

Vec::Vec(int l) {
    length = l;
    // Check out `allocating-arrays.cpp`.
    array = new int[l];
}

// Since we took a bite of our heap when we create the `array` data member, we
// can free that chunk of memory during our destructor function.
Vec::~Vec() {
    delete [] array;
}

int *Vec::get() const {
    return array;
}

int Vec::get_length() const {
    return length;
}

int main(void) {

    Vec *v = new Vec(7);

    v->get()[0] = 99;
    std::cout << v->get()[0] << std::endl;

    // Call the destructor.
    delete v;

    return 0;
}
