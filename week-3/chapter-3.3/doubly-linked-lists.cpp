// Central to doubly linked lists is the concept of "sentinel nodes."

// Sentinel nodes do not hold any meaningful values. Yes, they are nodes, but
// we simply use them to demarcate part of our list.

// In a doubly linked list, we have two sentinels nodes: 
// 1. one at the beginning, called the head;
// 2. and one at the end, called the tail.

#include <iostream>

// Nodes of a doubly linked list are called Doubly Linked Nodes.
class DoublyLinkedNode {
    friend class DoublyLinkedList;

    private:
        int value;
        // They are doubly linked because they have both a `next` and `prev`.
        DoublyLinkedNode *next;
        DoublyLinkedNode *prev;
};

class DoublyLinkedList {
    public:
        DoublyLinkedList();
        // Since we allocate memory, we should also have a constructor here.
        // ~DoublyLinkedList();
        
        bool empty() const;

        void add_node_to_head();
        void add_node_to_tail();

        void remove_head_node();
        void remove_tail_node();

    private:
        DoublyLinkedNode *head;
        DoublyLinkedNode *tail;
};

DoublyLinkedList::DoublyLinkedList() {
	// For initialization, we should be making two sentinel nodes: head and tail.
	// They should also point to each other.
	// Head always has NULL prev.
	// And tail always has NULL next.
	head = new DoublyLinkedNode;
	tail = new DoublyLinkedNode;
    head->next = tail;
    head->prev = NULL;
    tail->next = NULL;
}

// Define the destructor here latter ig.
// DoublyLinkedList::~DoublyLinkedList() {
// }

void DoublyLinkedList::add_node_to_head() {
    
}

int main(void) {
    DoublyLinkedList dll;

    return 0;
}
