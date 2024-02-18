#include "deque.hpp"
#include "deque-empty-exception.hpp"
#include <iostream>

Deque::Deque() {
    n = 0;
}

bool Deque::empty() const {
    return n == 0;
}

void Deque::push_to_front(const char &c) {
    dll.insert_node_after_head(c);
    n++;
}

void Deque::push_to_back(const char &c) {
    dll.insert_node_before_tail(c);
    n++;
}

char Deque::pop_front() {
    if (empty()) throw DequeEmpty("Tried to pop front of Deque, but Deque is empty");

    char front = dll.get_node_after_head_value();
    dll.remove_node_after_head();
    
    n--;

    return front;
}

char Deque::pop_back() {
    if (empty()) throw DequeEmpty("Tried to pop back of Deque, but Deque is empty");

    char back = dll.get_node_before_tail_value();
    dll.remove_node_before_tail();

    n--;

    return back;
}

char Deque::peek_front() const {
    if (empty()) throw DequeEmpty("Tried to peek front of Deque, but Deque is empty");

    char front = dll.get_node_after_head_value();
    return front;
}

char Deque::peek_back() const {
    if (empty()) throw DequeEmpty("Tried to peek back of Deque, but Deque is empty");

    char back = dll.get_node_before_tail_value();
    return back;
}
