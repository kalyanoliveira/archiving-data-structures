#include <iostream>

void bubble_sort_array(int a[], int n);

int main(void) {
    int a[10] = {8, 3, 4, 2, 5, 6, 4, 6, 7, 3};

    bubble_sort_array(a, 10);

    for (int i = 0; i < 10; i++) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    return 0;
}

void bubble_sort_array(int a[], int n) {
    int i, j;

    bool swapped;

    for (i = 0, swapped = false; i < n - 1; i++, swapped = false) {

        // For every element in the array,
        for (j = 0; j < (n - 1) - i; j++) {

            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                swapped = true;
            }
        }

        if (!swapped) break;

    }
}
