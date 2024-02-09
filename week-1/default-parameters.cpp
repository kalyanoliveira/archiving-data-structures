#include <iostream>

// We can create default parameters in functions!
// They should only be included in function prototypes (i.e., in the
// declaration).
int add_two_numbers(int a, int b = 0);

int main(void) {

    int x = 7;
    int y = 7;

    std::cout << add_two_numbers(x) << std::endl;
    std::cout << add_two_numbers(x, y) << std::endl;
    
    return 0;
}

// When we actually define that function, we omit the default parameter.
int add_two_numbers(int a, int b) {
    return a + b;
}
