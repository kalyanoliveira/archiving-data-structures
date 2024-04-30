#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>
#include <list>

// Sorts a `std::list<E>` given a comparator (of type `C`) between `E`s.
template <typename E, typename C>
void merge_sort(std::list<E>& l, const C& is_less_comparator) {
    typedef typename std::list<E>::iterator Iter;

    // Returns if `l` is already sorted (i.e. if the size of `l` is <= 1).
    if (l.size() <= 1) return;

    // Divides the sorting task midway between `l`, since `l` is not already
    // sorted.
    std::list<E> l1, l2;
    Iter iter = l.begin();
    // "For `l.size()/2` times in the first half of `l`."
    for (int i = 0; i < l.size()/2; i++) {
        l1.push_back(*iter); 
        ++iter;
    }
    // "For `l.size()/2)` times in the second half of `l`."
    for (int i = l.size()/2; i < l.size(); i++) {
        l2.push_back(*iter); 
        ++iter;
    }
    merge_sort(l1, is_less_comparator);
    merge_sort(l2, is_less_comparator);

    // Merges `l1` with `l2` correctly (this is where the "merge" sort happens).
    // Clears the original `std::list<E>` that got divided into two prior merging.
    l.clear();
    merge(l1, l2, l, is_less_comparator);
}

// Merges the `std::list<E>`s `l1` and `l2` into 
template <typename E, typename C>
void merge(std::list<E>& l1, 
           std::list<E>& l2, 
           std::list<E>& l, 
           const C& is_less_comparator) {

    // Adds the smallest `E`s from `l1` and `l2` to `l` until either `l1` or
    // `l2` become empty.
    while (!l1.empty() && !l2.empty()) {
        if ( is_less_comparator(*l1.begin(), *l2.begin()) ) {
            l.push_back(*l1.begin());
            l1.pop_front();
        } else {
            l.push_back(*l2.begin());
            l2.pop_front();
        }
    }

    // Adds the leftover `E`s from whatever list did not become empty.
    while (!l1.empty()) {
        l.push_back(*l1.begin());
        l1.pop_front();
    }
    while (!l2.empty()) {
        l.push_back(*l2.begin());
        l2.pop_front();
    }
}

#endif
