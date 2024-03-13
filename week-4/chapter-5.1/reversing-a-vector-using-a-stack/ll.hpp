#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.hpp"

class LinkedList {
    public: 
        LinkedList();
        ~LinkedList();

        bool empty() const;
        
        void front_insert(const int v);
        void front_remove();

        int get_front() const;

    private:
        Node *head;
};



#endif
