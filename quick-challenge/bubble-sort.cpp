#include <iostream>

void bubble_sort(int *a, int n);

int main(void) {
    int a[] = {7, 9, 10, 15, 4, 8, 3};
    int N = 7;

    for (int i = 0; i < N; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    bubble_sort(a, N);

    for (int i = 0; i < N; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

void bubble_sort(int *a, int n) {
    if (n <= 1) return;
    bool swapped;
    int prev;
    int curr;
    int sub_size;

    // For every possible subsize.
    for (sub_size = n; sub_size > 0; sub_size--) {
        // For every pair of elements in that subsize.
        for (prev = 0, curr = 1, swapped = false;
            curr < sub_size;
            prev++, curr++
        ) {
            // If prev > curr, swap.
            if (a[prev] > a[curr]) {
                int temp = a[prev];
                a[prev] = a[curr];
                a[curr] = temp;
                swapped = true;
            }
        }

        // If no swaps occured, break the subsize update early.
        if (swapped == false) break;
    }

}
