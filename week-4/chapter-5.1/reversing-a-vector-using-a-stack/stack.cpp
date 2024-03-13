#include "stack.hpp"
#include "ll.hpp"
#include "empty.hpp"

void Stack::push(const int v){
    ll.front_insert(v);
}

int Stack::pop(){
    if (ll.empty()) throw Empty("Stack is empty, cannot pop()");

    int v = ll.get_front();

    ll.front_remove();

    return v;
}

int Stack::peek() const{
    if (ll.empty()) throw Empty("Stack is empty, cannot peek()");
        
    return ll.get_front();
}
