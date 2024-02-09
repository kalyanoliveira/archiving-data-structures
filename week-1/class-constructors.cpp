// Classes can have multiple constructors! This is essentially a case of
// `function-overloading.cpp`.

#include <iostream>

class Counter {
    public:
        // This is the default constructor.
        Counter();
        // This is the "special," initializer-like constructor.
        Counter(const int n);
        // This is a "copy-like" constructor!
        Counter(const Counter &c);

        int get_count() const;

        void increase_count(const int n);

    private:
        int count;
};

Counter::Counter() {
    count = 0;
}

Counter::Counter(const int n) {
    count = n;
}

Counter::Counter(const Counter &c) {
    count = c.count;
}

int Counter::get_count() const {
    return count;
}

void Counter::increase_count(const int n) {
    count += n;
}

void print(const Counter c) {
    std::cout << "Counter: " << c.get_count() << std::endl;
}

int main(void) {
    // Here, we are using our special, initializer-like constructor!
    Counter c0(7);
    print(c0);
    
    // Two ways in which we can use the copy constructor. The second one might
    // look weird, but it's just compiler magic.
    Counter c1(c0);
    Counter c2 = c0;

    c1.increase_count(1);
    c2.increase_count(2);

    print(c1);
    print(c2);

    return 0;
}
