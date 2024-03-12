#include <iostream>
#include "ll.hpp"
#include "n.hpp"
#include "empty-exception.hpp"

LinkedList::LinkedList() {
    head = nullptr;
}

bool LinkedList::empty() const {
    return head == nullptr;
}

LinkedList::~LinkedList() {
    while (!empty()) remove_front();
}

void LinkedList::add_front(const int v) {
    Node *n = new Node;
    n->value = v;

    n->next = head;
    head = n;

    return;
}

void LinkedList::remove_front() {
    if (empty()) return;

    Node *to_remove = head;
    head = head->next;

    delete to_remove;
}

int LinkedList::get_front() const {
    if (empty()) throw EmptyException("Linked list is empty, cannot get_front()");
    return head->value;
}
