#include <iostream>

#include "ll.hpp"

int main(void) {
    LinkedList ll;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(0);
    ll.print();
    ll.print_backwards();

    LinkedList::Iterator iter = ll.begin();
    ++iter;
    ll.pop(iter);

    ll.print();
    ll.print_backwards();

    std::cout << *iter << std::endl;

    return 0;
}

