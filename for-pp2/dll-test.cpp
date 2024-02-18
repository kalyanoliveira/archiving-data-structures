#include <iostream>
#include "dll.hpp"

int main(void) {
    DLL dll;

    dll.insert_node_after_head('a');
    dll.insert_node_after_head('b');
    dll.insert_node_after_head('c');
    dll.insert_node_after_head('4');
    dll.insert_node_before_tail('a');
    dll.insert_node_before_tail('b');
    dll.insert_node_before_tail('c');
    dll.insert_node_before_tail('1');
    dll.test_linkage_by_printing();

    std::cout << dll.get_node_after_head_value() << std::endl;
    std::cout << dll.get_node_before_tail_value() << std::endl;
    dll.test_linkage_by_printing();

    std::cout << " --- " << std::endl;

    dll.remove_node_after_head();
    dll.remove_node_before_tail();
    dll.test_linkage_by_printing();
    std::cout << dll.get_node_after_head_value() << std::endl;
    std::cout << dll.get_node_before_tail_value() << std::endl;
    dll.test_linkage_by_printing();

    return 0;
}
