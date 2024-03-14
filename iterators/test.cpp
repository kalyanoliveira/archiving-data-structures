#include <iostream>
#include "iterated-dll.hpp"

int main(void) {
    IteratedDLL idll;

    idll.insert_front(1);
    idll.insert_front(2);
    idll.insert_front(3);
    idll.insert_front(4);

    IteratedDLL::Iterator iter = idll.get_first_iterator();
    IteratedDLL::Iterator last_position_iter = idll.get_last_iterator();

    for (; iter != last_position_iter; ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    return 0;
}
