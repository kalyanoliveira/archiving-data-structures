#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

// Sorts a `std::vector<E>` given a "is-less" comparator (of type `C`) for `E`s.
template <typename E, typename C>
void quick_sort(std::vector<E>& v, const C& is_less_comparator) {
    if (v.size() == 1) return;

    _quick_sort(v, 0, v.size() -1, is_less_comparator);

    return;
}

template <typename E, typename C>
void _quick_sort(
    std::vector<E>& v, 
    int a, 
    int b, 
    const C& is_less_comparator) {

    // If there are 0 or 1 elements left in the subrange to sort, we are
    // technically done sorting.
    if (a >= b) return;

    E pivot = v[b];

    int l = a;
    int r = b - 1;

    while (l <= r) {
        while (l <= r && !is_less_comparator(pivot, v[l])) l++;
        while (r >= l && !is_less_comparator(v[r], pivot)) r--;

        if (l < r) std::swap(v[l], v[r]);
    }

    std::swap(v[l], v[b]);

    _quick_sort(v, a, l - 1, is_less_comparator);
    _quick_sort(v, l + 1, b - 1, is_less_comparator);

    return;
}

#endif
