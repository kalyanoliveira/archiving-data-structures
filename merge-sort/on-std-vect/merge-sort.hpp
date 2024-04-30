#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>
#include <vector>

// Sorts a `std::vector<E>` given a "is-less" comparator object (of type `C`)
// for `E`s.
template <typename E, typename C>
void merge_sort(std::vector<E>& v, const C& is_less_comparator) {
    // Creates two `std::vector<E>`s, one that is empty (for output), and
    // another that just copies the input `v`.

    std::vector<E> v1(v);
    std::vector<E> v2(v.size());

    // Creates pointers to those two `std::vector<E>`s.
    std::vector<E>* in = &v1;
    std::vector<E>* out = &v2;

    // Sorts `v` by "merging contiguous pairs of subarrays (of equal size)" of
    // the merged versions of `v` that are obtained by "choosing a size for the
    // subarrays that starts at 1 and is doubled every time" and "passing the
    // resultant vector of one merge as input to the merge with the next
    // corresponding larger size", until the size of subarrays exceeds the size
    // of `v`.
    for (int size = 1; size < v.size(); size *= 2) {
        std::cout << "size is" << size << std::endl;
        // By increasing `start`, we are able to "merge contiguous pairs."
        for (int start = 0; start < v.size(); start += 2*size) {
            std::cout << "start is" << start << std::endl;
            merge(*in, *out, is_less_comparator, start, size);
        }
        // This is how we "pass the resultant vector of one merge to the merge
        // with the next corresponding larger size."
        // We are essentially saying "make the input of the next iteration the
        // output we got from this iteration.
        std::swap(in, out);
    }
    // We use `in` because of `std::swap(in, out);`.
    v = *in;
}

// This is just that same merge procedure we saw in the `std::list`-based
// version of merge sort, only this time we have to take into account that we
// are dealing with only two vectors.
template <typename E, typename C>
void merge(
    std::vector<E>& in, 
    std::vector<E>& out, 
    const C& is_less_comparator,
    int start,
    int size) {

    int i = start;
    int j = start + size;
    // Make the "end conditions" of i and j "proper."
    // That is, if we find out that the "end condition" index of i is beyond
    // the actual size of our entire array, let's just make the end condition
    // of i the size of the array.
    // The same applies for j.
    int i_end = (i + size < in.size()) ? (i + size) : (in.size());
    int j_end = (j + size < in.size()) ? (j + size) : (in.size());

    int k = start;

    while ((i < i_end) && (j < j_end)) {
        if (is_less_comparator(in[i], in[j])) {
            out[k] = in[i];
            k++;
            i++;
        } else {
            out[k] = in[j];
            k++;
            j++;
        }
    }

    while (i < i_end) {
            out[k] = in[i];
            k++;
            i++;
    }

    while (j < j_end) {
            out[k] = in[j];
            k++;
            j++;
    }

}

#endif
