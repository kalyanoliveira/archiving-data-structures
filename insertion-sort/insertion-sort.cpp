#include <iostream>
#define N 10

void insertion_sort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int floating = a[i];
        int prev = i - 1;

        while (prev >= 0 && a[prev] > floating) {
            a[prev + 1] = a[prev];
            prev--;
        }
        a[prev + 1] = floating;
    }
}

int main(void) {
    int a[N] = {3, -3, 1, 5, -6, 1, 4, -2, 7, 10};

    std::cout << "Before sorting:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    insertion_sort(a, N);

    std::cout << "After sorting:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
