#include <iostream>

template<typename T>
class Something {
    public:
        Something(T v);

        void print();

    private:
        T value;
};

// Notice the "scope resolution" here: it includes `<T>`, which we call "the
// template parameter.
template<typename T>
Something<T>::Something(T v) {
    value = v; 
}

template<typename T>
void Something<T>::print() {
    std::cout << value << std::endl;
}

int main(void) {
    Something<int> s(10);

    s.print(); 

    return 0;
}
