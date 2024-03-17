#include <iostream>
#include "binary-tree.hpp"

int main(void) {
    BinaryTree<int> bt;

    bt.add_root();
    BinaryTree<int>::Position p = bt.get_root();
    bt.expand_external(p);
    p = p.left(); 
    bt.expand_external(p);

    List<BinaryTree<int>::Position> ps = bt.get_positions();
    List<BinaryTree<int>::Position>::Iterator temp = ps.get_begin_iter();
    List<BinaryTree<int>::Position>::Iterator last = ps.get_end_iter();
    int count = 0;
    for(count = 0;
        temp != last;
        ++temp, count++) 
    {
        **temp = count;    
    }

    // Outputs `0 ( 1 ( 2 3 ) 4 )`
    bt.preorder_print();
    bt.inorder_print();

    // Gets an iter to an external node and call `remove_above_external` on it.
    BinaryTree<int>::Position exter = p.left();
    bt.remove_above_external(exter);

    bt.preorder_print();

    return 0;
}
