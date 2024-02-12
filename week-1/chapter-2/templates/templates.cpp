// Templates are awesome! Here's a simple generic function.

#include <iostream>

// Essentialy, you can think of this like a #define statement, from standard C.
template<typename T>
T min(T a, T b) {
    if (a < b) return a;
    else return b;
}

int main(void) {
    int a = 7;
    int b = 11;

    std::cout << min<int>(a, b) << std::endl;
 
    return 0;
}
