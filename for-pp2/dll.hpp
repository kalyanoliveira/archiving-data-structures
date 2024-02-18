// Just a simple doubly linked list interface.
#ifndef DLL_H
#define DLL_H

#include "dll-node.hpp"
#include <string>

class DLL {
    public:
        DLL();
        // DLL allocates, hence it must have a destructor.
        ~DLL();

        bool empty() const;

        void insert_node_after_head(const std::string &v);
        void insert_node_before_tail(const std::string &v);

        void remove_node_after_head();
        void remove_node_before_tail();

        // This'll basically try to print the list forwards and backwards; a
        // good way to check if any mistakes were made during the
        // implementation of this interface.
        void test_linkage_by_printing() const;

        // Let's just assume that the user never does anything stupid with
        // these. 
        // This allows us to not have to worry about any exceptions here, and
        // only have to make sure that things work over on the deque-side of
        // things.
        std::string get_node_after_head_value() const;
        std::string get_node_before_tail_value() const;

    private:
        // These are sentinel nodes: they won't hold any value that is
        // meaningful to us.
        DLNode *head;
        DLNode *tail;
};

#endif //DLL_H
