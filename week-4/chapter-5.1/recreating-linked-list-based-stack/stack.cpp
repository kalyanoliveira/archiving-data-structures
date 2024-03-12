#include "stack.hpp"

int Stack::peek() const {
    return ll.get_front();
}

void Stack::push(const int v) {
    ll.add_front(v);
}

int Stack::pop() {
    // This can throw EmptyException.
    int v = ll.get_front();
    ll.remove_front();
    return v;
}
