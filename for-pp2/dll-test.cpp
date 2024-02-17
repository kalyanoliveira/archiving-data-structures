#include <iostream>
#include "dll.hpp"

int main(void) {
    DLL dll;

    dll.insert_node_after_head('a');
    dll.insert_node_after_head('b');
    dll.insert_node_after_head('c');
    dll.test_linkage_by_printing();

    dll.insert_node_before_tail('a');
    dll.insert_node_before_tail('b');
    dll.insert_node_before_tail('c');
    dll.test_linkage_by_printing();

    dll.remove_node_after_head();
    dll.remove_node_before_tail();
    dll.test_linkage_by_printing();

    dll.remove_node_after_head();
    dll.remove_node_before_tail();
    dll.remove_node_after_head();
    dll.remove_node_before_tail();
    dll.test_linkage_by_printing();

    return 0;
}
