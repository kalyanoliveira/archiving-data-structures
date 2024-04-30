#include <iostream>

#include "ll.hpp"

LinkedList::LinkedList() {
    tail = new Node(0);
    head = tail;
}

LinkedList::~LinkedList() {
    while (!empty()) pop_front();
}

bool LinkedList::empty() {
    return head == tail;
}

int LinkedList::size() {
    int count = 0;
    for (Node* temp = head; temp != tail; temp = temp->next, count++);
    return count;
}

void LinkedList::push_front(int v) {
    Node* newn = new Node(v);
    newn->next = head;
    head = newn;
}

void LinkedList::pop_front() {
    if (empty()) return;
    Node* to_remove = head;
    head = head->next;
    delete to_remove; 
}

LinkedList::Iterator LinkedList::begin() {
    return Iterator(*this, head);
}

LinkedList::Iterator LinkedList::end() {
    return Iterator(*this, tail);
}

void LinkedList::push_before(int v, Iterator& iter) {
    Node* newn = new Node(v);

    Node* temp;
    Node* temp_prev;
    for (temp = head, temp_prev = nullptr;
         temp != iter.node;
         temp_prev = temp, temp = temp->next);

    if (temp_prev == nullptr) {
        newn->next = head;
        head = newn;
    } else {
        newn->next = iter.node;
        temp_prev->next = newn;
    }
}

void LinkedList::push_after(int v, Iterator& iter) {
    Node* newn = new Node(v);
    newn->next = iter.node->next;
    iter.node->next = newn;
}

void LinkedList::pop(Iterator& iter) {
    if (empty()) return;

    Node* temp;
    Node* temp_prev;
    for (temp = head, temp_prev = nullptr;
         temp != iter.node;
         temp_prev = temp, temp = temp->next);

    if (temp_prev == nullptr) {
        Node* to_remove = head;
        head = head->next;
        delete to_remove;
        iter.node = head;
    } else {
        Node* to_remove = iter.node;
        temp_prev->next = iter.node->next;
        iter.node = iter.node->next;
        delete to_remove;
    }
}

void LinkedList::pop_before(Iterator& iter) {
    Node* temp;
    Node* temp_prev;
    for (temp = head, temp_prev = nullptr;
         temp != iter.node;
         temp_prev = temp, temp = temp->next);

    if (temp_prev == nullptr) {

    } else {

    }
}

void LinkedList::pop_after(Iterator& iter) {

}

void LinkedList::clear() {

}

void LinkedList::print() {
    std::cout << "Printing forwards: " << std::endl;
    for (Node* temp = head; temp != tail; temp = temp->next) {
        std::cout << **temp << " ";
    }
    std::cout << std::endl;
}

void LinkedList::print_backwards() {
    std::cout << "Printing backwards: " << std::endl;
    Iterator iter = (end());
    do {
        --iter;
        std::cout << *iter << " ";
    } while (iter != begin());
    std::cout << std::endl;
}

int& LinkedList::Node::operator*() {
    return value;
}

int& LinkedList::Iterator::operator*() {
    return node->value;
}

void LinkedList::Iterator::operator++() {
    if (node->next == nullptr);
    else {
        node = node->next;    
    }
}

void LinkedList::Iterator::operator--() {
    Node* target = node;
    Node* temp;
    Node* temp_prev;
    for (temp = _linkedlist.head, temp_prev = nullptr;
         temp != target;
         temp_prev = temp, temp = temp->next);

    if (temp_prev == nullptr) return;
    else {
        node = temp_prev;
    }
}

bool LinkedList::Iterator::operator==(const Iterator& other) {
    if ((this->node) == other.node) return true;
    else return false;
}

bool LinkedList::Iterator::operator!=(const Iterator& other) {
    if ((this->node) != other.node) return true;
    else return false;
}

