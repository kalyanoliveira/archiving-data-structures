#include "dll.hpp"
#include "dll-node.hpp"
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
    // location
    DLNode *new_node = new DLNode;

    // Set the value of that new node.
    new_node->- value= v;

    // Make the next of the new node be the next of head-node.
    new_node->next = head->next;

    // Make the prev of the new node be the head-node.
    new_node->prev = head;
    
    // Make the prev of the next of the head-node be the new node.
    (head->next)->prev = new_node;

    // Make the next of the head-node be the new node.
    head->next = new_node;
}

void DLL::insert_node_before_tail(const int &v) {
    // Create space for a new node in memory, and get a pointer to that
    // location
    DLNode *new_node = new DLNode;

    // Set the value of that new node.
    new_node->- value= v;

    // Make the prev of the new node be the prev of the tail-node.
    new_node->prev = tail->prev;

    // Make the next of the new node be the tail-node.
    new_node->next = tail;

    // Make the next of the prev of the tail-node be the new node.
    (tail->prev)->next = new_node;

    // Make the prev of the tail-node be the new node.
    tail->prev = new_node;
}

void DLL::remove_node_after_head() {
    // Bind a pointer to the node that we need to delete.
    DLNode *node_to_delete = head->next;

    // Make the next of the head-node be the next of the node that we need to
    // delete.
    head->next = node_to_delete->next;

    // Make the prev of the next of the node that we need to delete be the head.
    (node_to_delete->next)->prev = head;

    // Free up the memory space occupied by the node that we need to delete.
    delete node_to_delete;
}

void DLL::remove_node_before_tail() {
    // Bind a pointer to the node that we need to delete.
    DLNode *node_to_delete = head->next;

    // Make the prev of the tail-node be the prev of the node that we need to
    // delete.
    (tail->prev) = node_to_delete->prev;

    // Make the next of the prev of the node that we need to delete be the
    // tail.
    (node_to_delete->prev)->next = tail;
    
    // Free up the memory space occupied by the node that we need to delete.
    delete node_to_delete;
}

void DLL::test_linkage_by_printing() {
    std::cout << "DLL: ";
    std::cout << "(Printing forwards)";

    for (DLNode *temp = head->next; temp->next != NULL; temp=temp->next) {
    }
}
