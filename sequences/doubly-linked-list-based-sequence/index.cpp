#include <iostream>
#include "sdll.hpp"

int main(void) {
    SequencedDLL sdll;

    sdll.front_insert(7);
    sdll.front_insert(8);
    sdll.front_insert(9);
    sdll.front_insert(10);
    sdll.back_insert(0);
    sdll.back_insert(1);
    sdll.back_insert(2);
    sdll.back_insert(3);
    sdll.print();

    sdll.front_remove();
    sdll.back_remove();
    sdll.front_remove();
    sdll.back_remove();
    sdll.print();

    SequencedDLL::SDLLIterator iter = sdll.find_iter_at_index(2);

    for (SequencedDLL::SDLLIterator finish = sdll.end();
         iter != finish;
         ++iter)
    {
        std::cout << *iter << " ";                                
    }
    std::cout << std::endl;

    iter = sdll.find_iter_at_index(1);

    std::cout << sdll.find_index_of_iter(iter);

    return 0;
}
