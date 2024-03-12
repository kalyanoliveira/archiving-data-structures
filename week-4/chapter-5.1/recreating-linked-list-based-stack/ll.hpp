#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "n.hpp"

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();

        bool empty() const;

        void add_front(const int v);
        void remove_front();
        
        int get_front() const;

    private:
        Node *head;
};

#endif
