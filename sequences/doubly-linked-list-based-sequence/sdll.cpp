#include <iostream>
#include "sdll.hpp"

SequencedDLL::SequencedDLL(){
    head = new Node;
    tail = new Node;

    head->next = tail;
    tail->prev = head;

    head->prev = nullptr;
    tail->next = nullptr;
}

SequencedDLL::~SequencedDLL(){
    while (!empty()) front_remove();
}

bool SequencedDLL::empty() const{
    return head->next == tail;
}

int SequencedDLL::size() const{
    int count = 0;

    for (Node *temp = head->next;
         temp != tail;
         temp = temp->next)
    {
        count++;
    }

    return count;
}


int &SequencedDLL::SDLLIterator::operator*() const {
    return node->value;
}

bool SequencedDLL::SDLLIterator::operator==(const SDLLIterator &other) const {
    return this->node == other.node;
}

bool SequencedDLL::SDLLIterator::operator!=(const SDLLIterator &other) const {
    return this->node != other.node;
}

SequencedDLL::SDLLIterator &SequencedDLL::SDLLIterator::operator++() {
    this->node = this->node->next;
    return *this;
}

SequencedDLL::SDLLIterator &SequencedDLL::SDLLIterator::operator--() {
    this->node = this->node->prev;
    return *this;
}


SequencedDLL::SDLLIterator::SDLLIterator(Node *n) {
    node = n;
}

SequencedDLL::SDLLIterator SequencedDLL::begin() const {
    return SDLLIterator(head->next);
}

SequencedDLL::SDLLIterator SequencedDLL::end() const {
    return SDLLIterator(tail);
}

void SequencedDLL::insert_before(const SequencedDLL::SDLLIterator &position, const int v) {
    Node *tail_like = position.node;

    Node *n = new Node;

    n->value = v;

    n->next = tail_like;
    n->prev = tail_like->prev;
    n->prev->next = n;
    tail_like->prev = n;

    return;
}

void SequencedDLL::insert_after(const SequencedDLL::SDLLIterator &position, const int v) {
    Node *head_like = position.node;

    Node *n = new Node;
    
    n->value = v;

    n->prev = head_like;
    n->next = head_like->next;
    n->next->prev = n;
    head_like->next = n;

    return;
}

void SequencedDLL::remove(const SequencedDLL::SDLLIterator &position) {
    Node *to_remove = position.node;

    Node *before = to_remove->prev;
    Node *after = to_remove->next;

    before->next = after;
    after->prev = before;

    delete to_remove;

    return;
}

SequencedDLL::SDLLIterator SequencedDLL::find_iter_at_index(const int i) const {
    Node *temp;
    int j;

    // Find the node located at the given index.
    for (j = 0, temp = head->next; 
         j < i;
         j++, temp=temp->next);
        
    return SDLLIterator(temp);
}

int SequencedDLL::find_index_of_iter(const SequencedDLL::SDLLIterator &iter) const {
    int count;
    SDLLIterator temp(head->next);

    for (count = 0;
         temp.node != iter.node;
         ++temp, count++);

    return count;
}

void SequencedDLL::front_insert(const int v) {
    insert_after(--(begin()), v);

    return;
}

void SequencedDLL::back_insert(const int v) {
    insert_before(end(), v);
    return;
}


void SequencedDLL::front_remove() {
    remove(begin());
    return;
}

void SequencedDLL::back_remove() {
    // I kind of hate this.
    remove( --(end()) );
    return;

}

void SequencedDLL::print() const {
    for (Node *temp = head->next;
         temp != tail;
         temp = temp->next)
    {
        std::cout << temp->value <<  " ";
    }
    std::cout << std::endl;

    for (Node *temp = tail->prev;
         temp != head;
         temp = temp->prev)
    {
        std::cout << temp->value << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;

    return;
}
    
