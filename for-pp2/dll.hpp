// Just a simple doubly linked list interface.
#include "dll_node.hpp"

#ifndef DLL_H
#define DLL_H

class DLL {
    public:
        DLL();
        // DLL allocates, hence it must have a destructor.
        ~DLL();

        bool empty() const;

        void insert_node_after_head(const char &v);
        void insert_node_before_tail(const char &v);

        void remove_node_after_head();
        void remove_node_before_tail();

        // This'll basically try to print the list forwards and backwards; a
        // good way to check if any mistakes were made during the
        // implementation of this interface.
        void test_linkage_by_printing();

    private:
        // These are sentinel nodes: they won't hold any value that is
        // meaningful to us.
        DLNode *head;
        DLNode *tail;
};

#endif //DLL_H
