#include <iostream>

void printing_stuff(const int &target);

int main(void) 
{
    int n = 7;
    
    // In the actual function call, though, you do not pass an address.
    printing_stuff(n);
    return 0;
}

// In a function, we can create a "constant reference:" a parameter that
// receives a value that it is not supposed to change.
void printing_stuff(const int &target) {
    // Since this is a reference, and not a pointer, we do not use `*target`:
    std::cout << "This is the target: " << target << std::endl;

    // For instance, this kind of operation would be invalid:
    //target = 7;
}

