#include "ll.hpp"
#include "n.hpp"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    while (!empty()) front_remove();
}

int LinkedList::size() const {
    int count = 0;
    for (Node *temp = head;
        temp != nullptr; 
        temp=temp->next, count++
    );

    return count;
}

bool LinkedList::empty() const {
    return head == nullptr;
}

void LinkedList::front_insert(const int v) {
    Node *new_node = new Node;

    new_node->value = v;

    new_node->next = head->next;
    head = new_node;

    return;
}

void LinkedList::front_remove() {
    if (empty()) return;

    Node *to_remove = head;

    head = head->next;

    delete to_remove;

    return;
}

void LinkedList::back_insert(const int v) {
    Node *new_node = new Node;
    new_node->value = v;

    // Find the last node.
    Node *last_node;
    for (last_node = head;
         last_node->next != nullptr;
         last_node = last_node->next
    );

    last_node->next = new_node;
    new_node->next = nullptr;
    
    return;
}

void LinkedList::back_remove() {
    if (empty()) return;

    // This is actually so much worse because we need both a pointer to the
    // last node *and* the second-to-last node.
    Node *last;
    Node *second_to_last;
    for (last = head, second_to_last = nullptr;
        last->next != nullptr;
        // We need to update the second_to_last node first.
        second_to_last = last, last = last->next
    );

    // And if our pointer to the second_to_last_node is still NULL, this means
    // that we only have one node in the list.
    if (second_to_last == nullptr) {
        head = nullptr;
        delete last;
        return;
    }

    second_to_last->next = nullptr; 
    delete last;

    return;
}

void LinkedList::insert_after(Node &n, const int v) {
    Node *new_node = new Node;
    new_node->value = v;
    
    new_node->next = n.next;
    n.next = new_node;

    return;
}

void LinkedList::insert_before(const Node &n, const int v) {
    Node *new_node = new Node;
    new_node->value = v;

    // We have to do something similar to `back_remove()` here. 
    Node *before;
    Node *target;
    for (before = nullptr, target = head;
        target != &n;
        before = target, target=target->next
    );

    if (before == nullptr) {
        new_node->next = target;
        head = new_node;
    }

    new_node->next = target;
    before->next = new_node;

    return;
}


void LinkedList::sort() {
    // I'll just do bubble sort because I need to practice that shit.
}


// This should be done recursively.
void LinkedList::print() {

}
