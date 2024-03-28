#include <iostream>
#include <vector>

#include "quick-sort.hpp"

class int_is_less_comparator {
    public: 
    bool operator()(const int& first, const int& second) const {
        return first < second;
    }
};

int main(void) {
    
    std::vector<int> v = {5, 3, -4, 1, 6, -6};

    quick_sort<int, int_is_less_comparator>(v, int_is_less_comparator());

    for (std::vector<int>::iterator iter = v.begin();
         iter != v.end();
         iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    return 0;
}
