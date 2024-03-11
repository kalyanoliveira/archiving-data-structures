#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "n.hpp"

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();

        bool empty() const;
        int size() const;

        void front_insert(const int v);
        void front_remove();

        void back_insert(const int v);
        void back_remove();

        void insert_after(Node &n, const int v);
        void insert_before(const Node &n, const int v);

        void sort();

        // This should be done recursively.
        void print();
        void print_internal(Node *n);
        
    private:
        Node *head;
};

#endif
