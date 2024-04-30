#include <stdio.h>
#define N 10

// Actual function we should use.
void merge_sort(int a[], int n);
// Function used by merge_sort, you should not call it.
void _merge(int a[], int b[], int c[], int na, int nb, int nc);

int main(void) {
    int a[N] = {5, 6, -6, -3, 3, -1, 8, -7, 9, 10};

    merge_sort(a, N);

    for (int i = 0; i < N; i++) printf("%d\n", a[i]);
    printf("\n");
}

void merge_sort(int a[], int n) {
    if (n <= 1) return;

    // The size of array `b`.
    int sizeb = n/2;
    // The size of array `c`.
    int sizec = n - n/2;

    // `b` should get the elements of `a` in the interval of $[0, sizeb)$.
    int b[sizeb];
    for (int i = 0; i < sizeb; i++) {
         b[i] = a[i];
    }

    // `c` should get the elements of `a` in the interval of $[sizeb, n)$.
    int c[sizec];
    for (int i = sizeb; i < n; i++) {
        // We do `i - sizeb` such that `c` gets indices 0, 1, 2, 3, and so on.
        c[i - sizeb] = a[i];
    }

    // Recursion!
    merge_sort(b, sizeb);
    merge_sort(c, sizec);

    _merge(a, b, c, n, sizeb, sizec);

    return;
}

void _merge(int a[], int b[], int c[], int na, int nb, int nc) {
    // We keep track of what index we are currently at for each array.
    int ia = 0;
    int ib = 0;
    int ic = 0;

    while (ib < nb && ic < nc) {
        // Append to `a` the smaller element: "is it `b[ib]`, or is it `c[ib]`?"
        a[ia] = (b[ib] < c[ic]) ? b[ib++] : c[ic++];
        ia++;
    }

    // After the while loop above completes, we either reached the end of `b` or `c`.
    // If we reached the end of `b`, we still have some elements in `c`. Let's append them.
    // Conversely, if we reached the end of `c`, we still have some elements in `b` to append.
    while (ib < nb) {
        a[ia++] = b[ib++];
    }

    while (ic < nc) {
        a[ia++] = c[ic++];
    }
}
