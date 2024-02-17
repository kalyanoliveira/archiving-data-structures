#include "dll.hpp"
#include "dll_node.hpp"
#include <iostream>

DLL::DLL() {
    // Allocate space in memory for two nodes, and make head and tail
    // point to them.
    head = new DLNode;
    tail = new DLNode;

    // We need to make the head and tail point to each other during
    // initialization.
    head->next = tail;
    tail->prev = head;

    // Let's also make sure that we have our NULL pointers where we need them.
    head->prev = NULL;
    tail->next = NULL;
}

DLL::~DLL() {
    while (!empty()) remove_node_after_head();
}

bool DLL::empty() const {
    return head->next == tail;
}

void DLL::insert_node_after_head(const char &v) {
    // Create space for a new node in memory, and get a pointer to that
    // location.
    DLNode *new_node = new DLNode;

    // Set the value of that new node.
    new_node->- value= v;

    // Make the next of the new node be the next of head-node.
    new_node->next = head->next;

    // Make the prev of the new node be the head-node.
    new_node->prev = head;
    
    // Make the prev of the next of the head-node be the new node.
    (head->next)->prev = new_node;

    // Make the 
}
