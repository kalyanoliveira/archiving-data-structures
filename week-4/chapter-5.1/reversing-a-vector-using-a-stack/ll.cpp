#include "ll.hpp"
#include "empty.hpp"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    while (!empty()) front_remove();
}

bool LinkedList::empty() const {
    return head == nullptr;
}

void LinkedList::front_insert(const int v) {
    Node *n = new Node;

    n->value = v;
    n->next = head;
    head = n;
}

void LinkedList::front_remove() {
    if (empty()) throw Empty("Linked list is empty, cannot front_remove()");

    Node *n = head;
    head = head->next;
    delete n;

    return;
}

int LinkedList::get_front() const {
    if (empty()) throw Empty("Linked list is empty, cannot front_remove()");

    return head->value;
}
