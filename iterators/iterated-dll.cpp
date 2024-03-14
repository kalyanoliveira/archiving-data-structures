#include "iterated-dll.hpp"
#include <iostream>

IteratedDLL::Iterator::Iterator(Node *node) {
    internal_node = node;
}

int &IteratedDLL::Iterator::operator*() {
    return internal_node->value;
}

bool IteratedDLL::Iterator::operator==(const Iterator &other) const {
    return internal_node == other.internal_node;

}
bool IteratedDLL::Iterator::operator!=(const Iterator &other) const {
    return internal_node != other.internal_node;
}

IteratedDLL::Iterator &IteratedDLL::Iterator::operator++() {
    internal_node = internal_node->next;
    return *this;
}

IteratedDLL::Iterator &IteratedDLL::Iterator::operator--() {
    internal_node = internal_node->prev;
    return *this;
}

IteratedDLL::IteratedDLL() {
    head = new Node;
    tail = new Node;

    head->next = tail;
    tail->prev = head;

    head->prev = nullptr;
    tail->next= nullptr;
}

IteratedDLL::~IteratedDLL() {
    while (!empty()) remove_front();
}

bool IteratedDLL::empty() const {
    return head->next == tail;
}

int IteratedDLL::size() const {
    if (empty()) return 0; 

    int count = 0;
    for (Node *temp = head->next;
        temp != tail;
        temp = temp->next) 
    {
        count++; 
    }

    return count;
}

void IteratedDLL::insert_front(const int v) {
    Node *n = new Node;

    n->value = v;

    n->prev = head;
    n->next = head->next;
    n->next->prev = n;
    head->next = n;

    return;
}

void IteratedDLL::insert_back(const int v) {
    Node *n = new Node;

    n->value = v;

    n->next = tail;
    n->prev = tail->prev;
    n->prev->next = n;
    tail->prev = n;

    return;
}

void IteratedDLL::remove_front() {
    // If the list is empty, simply return.
    if (empty()) return;

    // We need to obtain a pointer to the node that we have to remove.
    Node *to_remove = head->next;
    
    // We need to make the next of the sentinel header node be the next of the
    // node that we have to remove.
    head->next = to_remove->next;

    // Then, we need to make the prev of the next of the node that we need to
    // remove be the sentinel header node.
    to_remove->next->prev = head;

    // Then, we should just be able to perform the deletion operation, and 
    // return.
    delete to_remove;

    return;
}

void IteratedDLL::remove_back() {
    if (empty()) return;    

    Node *to_remove = tail->prev;

    tail->prev = to_remove->prev;
    to_remove->prev->next = tail;

    delete to_remove;

    return;
}

IteratedDLL::Iterator IteratedDLL::get_first_iterator() {
    return Iterator(head->next);
}

IteratedDLL::Iterator IteratedDLL::get_last_iterator() {
    return Iterator(tail);
}

void IteratedDLL::insert_before(const Iterator &i, const int v) {
    // We are able to access `internal_node` from `IteratedDLL` because
    // `IteratedDLL` is a friend of `Iterator`, which is the type of `i`.
    Node *tail_like = i.internal_node;

    Node *n = new Node;

    n->value = v;

    n->next = tail_like;
    n->prev = tail_like->prev;
    n->prev->next = n;
    tail_like->prev = n;

    return;
}

void IteratedDLL::insert_after(const Iterator &i, const int v) {
    Node *head_like = i.internal_node;

    Node *n = new Node;

    n->value = v;

    n->prev = head_like;
    n->next = head_like->next;
    n->prev->next = n;
    head_like->next = n;

}

void IteratedDLL::remove(Iterator &i) {
    Node *to_remove = i.internal_node;

    Node *before = i.internal_node->prev;
    Node *after = i.internal_node->next;

    before->next = after;
    after->prev = before;

    delete to_remove;

    return;
}

void IteratedDLL::print() const {
    for (Node *temp = head->next;
        temp != tail;
        temp = temp->next)
    {
        std::cout << temp->value << " ";
    }
    std::cout << std::endl;

    for (Node *temp = tail->prev;
        temp != head;
        temp = temp->prev)
    {
        std::cout << temp->value << " ";
    }
    std::cout << std::endl;
}
