// C++ also allows us to define nested classes, which are a useful concept in
// data structures.

// I won't spend too much time here, but I am just demonstrating functionality.

#include <iostream>
#include <string>

class Car {
    public: 
        class Engine {
            public:
                Engine(std::string s);
                std::string something;
        };
};

Car::Engine::Engine(std::string s) {
    something = s;
}

int main(void) {
    Car c;
    Car::Engine e("hi");

    std::cout << e.something << std::endl;

    return 0;
}
