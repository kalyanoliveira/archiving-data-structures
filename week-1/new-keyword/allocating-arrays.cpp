#include <iostream>

int main(void)
{
    // We can also allocate chunks of heap memory for arrays with the `new`
    // operator:
    int *a = new int[1000];
    
    // There's not much more special about this array, other than it can be
    // allocated during runtime.

    // Once your done using it, you have to deallocate it.
    // But you don't just use `delete`.
    // Instead, you use `delete []`.
    delete [] a;

    return 0;
}
