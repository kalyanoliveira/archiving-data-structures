#include <stdio.h>
#include <stdlib.h>

void merge_sort(int a[], int n);
void _merge(int in[], int out[], int len_in_out, int start, int size);

int main(void) {
    int len_a = 10;
    int a[10] = {5, 6, -6, -3, 3, -1, 8, -7, 9, 10};

    merge_sort(a, len_a);

    for (int i = 0; i < len_a; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void merge_sort(int a[], int n) {
    int *in = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        in[i] = a[i];
    }

    int *out = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        out[i] = 0;
    }

    for (int size = 1; size < n; size *= 2) {
        for (int start = 0; start < n; start += 2*size) {
            _merge(in, out, n, start, size);
        }
        int *temp = in;
        in = out;
        out = temp;
    }

    for (int i = 0; i < n; i++) {
        a[i] = in[i];
    }
}

void _merge(int *in, int *out, int len_in_out, int start, int size) {
    int i = start;
    int i_end = (i + size < len_in_out) ? i + size : len_in_out;

    int j = i_end;
    int j_end = (j + size < len_in_out) ? j + size : len_in_out;

    printf("i: %d, i_end: %d, j: %d, j_end: %d\n", i, i_end, j, j_end);

    int k = start;

    while ((i < i_end) && (j < j_end)) {
        if (in[i] < in[j]) out[k++] = in[i++];    
        else out[k++] = in[j++];
    }

    while (i < i_end) out[k++] = in[i++];
    while (j < j_end) out[k++] = in[j++];
}
