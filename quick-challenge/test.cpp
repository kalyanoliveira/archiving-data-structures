#include <iostream>
#include "ll.hpp"
#include "n.hpp"

int main(void) {
    LinkedList ll;

    ll.front_insert(7);
    ll.back_insert(5);
    ll.back_insert(10);
    ll.back_insert(4);
    ll.sort();
    ll.print();

    Node v;
}
