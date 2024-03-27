#include <iostream>
#include <list>

#include "merge_sort.hpp"

class int_is_less_comparator {
    public: 
    bool operator()(const int& first, const int& second) const {
        return first < second;
    }
};

int main(void) {
    std::list<int> l = {7, -4, 3, 3, 13, -2};

    int_is_less_comparator is_less_comparator;

    merge_sort<int, int_is_less_comparator>(l, is_less_comparator);

    for (std::list<int>::iterator iter = l.begin();
         iter != l.end();
         iter++) {
    
         std::cout << *iter << " ";
    }
    std::cout << std::endl;

    return 0;
}

void merge_sort();
