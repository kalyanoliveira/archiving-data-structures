#include <stdio.h>
#define N 10

void in_place_quick_sort(int a[], int n);
void _in_place_quick_sort(int a[], int istart, int iend);

int main(void) {
    int a[N] = {5, 6, -6, -3, 3, -1, 8, -7, 9, 10};

    in_place_quick_sort(a, N);

    for (int i = 0; i < N; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void in_place_quick_sort(int a[], int n) {
    if (n <= 1) return;

    _in_place_quick_sort(a, 0, n - 1);

    return;
}

void _in_place_quick_sort(int a[], int istart, int iend) {
    if (istart >= iend) return;

    //  istart                 iend
    // [4, -3, 7, -4, 6, 9, 5, 8]
    //  il                  ir ipivot
    // "index_pivot."
    int ipivot = iend;
    // "index_left."
    int il = istart;
    // "index_right."
    int ir = iend - 1;

    // While the "left" index is to the right of (or exactly at) the "right" index.
    // GOOD
    // [4, -3, 7, -4, 6, 9, 5, 8]
    //  il            ir       ipivot       
    // GOOD
    // [4, -3, 7, -4, 6, 9, 5, 8]
    //                il
    //                ir       ipivot       
    // BAD
    // [4, -3, 7, -4, 6, 9, 5, 8]
    //                ir il    ipivot       
    while (il <= ir) {
        // Keep nudging "left" rightwards until it finds an element larger
        // than the pivot element, but that is also to the right of the "right"
        // index.
        // [4, -3, 7, -4, 6, 9, 5, 8]
        //  il-->               ir ipivot
        while (il <= ir && a[il] <= a[ipivot]) il++;

        // Keep nudging "right" leftwards until it finds an element smaller
        // than the pivot element, but that is also to the left of the "left"
        // index.
        // [4, -3, 7, -4, 6, 9, 5, 8]
        //                   <--ir ipivot
        //                   il
        while (ir >= il && a[ir] >= a[ipivot]) ir--;

        // Swap the positions of `il` and `ir`, but only if these positions do
        // not coincide.
        if (il < ir) { 
            int temp = a[il];
            a[il] = a[ir];
            a[ir] = temp;
        }
    }

    // What the above accomplished was something like this:
    // [4, -3, 7, -4, 6, 5, 9, 8]
    //                   ir il ipivot
    // Notice how, if we swap `a[il]` and `a[ipivot]`, we'll have all elements
    // larger than `a[ipivot]` to the right of `il`, and all elements smaller
    // than `a[ipivot]` to the left of `il`.
    // [4, -3, 7, -4, 6, 5, 8, 9]
    //                   ir il ipivot
    // And, of course, at `il`, we'll have our `a[pivot]` (before the swap
    // operation).
    int temp = a[il];
    a[il] = a[ipivot];
    a[ipivot] = temp;

    // Now, we call do our recursion magic!
    //  istart                 iend
    // [4, -3, 7, -4, 6, 5, 8, 9]
    //                   ir il ipivot
    // ---------------------  ---
    //        sort!           sort!
    _in_place_quick_sort(a, istart, il - 1);
    _in_place_quick_sort(a, il + 1, iend);

    return;
}
