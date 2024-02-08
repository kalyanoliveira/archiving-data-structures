//Enums are just a way to create named values.

#include <iostream>

int main(void)
{
        
    // Here's an example of with days of the week:
    enum Day {M, T, W, R, F, S, U};

    // We can then declare a new variable, `today`, which is of type of that
    // enum `Day`.
    Day today = M;
    std::cout << today << std::endl;

    today = T;
    std::cout << today << std::endl;

    today = W;
    std::cout << today << std::endl;

    today = R;
    std::cout << today << std::endl;

    today = F;
    std::cout << today << std::endl;

    today = S;
    std::cout << today << std::endl;

    today = U;
    std::cout << today << std::endl;
    return 0; 
}
