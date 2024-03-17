// If I am going to do a binary tree, I need a templated list.
// So that my binary_tree.positions() method can return a
// `List<BinaryTree::Position>`, or something like that.

#ifndef TEMPLATED_LIST_H
#define TEMPLATED_LIST_H

#include <iostream>

template <typename T>
class List {
    private:
        // A `List::Node` holds a pointer a `T`.
        struct Node {
            T value; 
            Node *next;
            Node *prev;
            Node() : value(0), next(nullptr), prev(nullptr) {}
        };

    public:
        List();
        ~List();

        bool empty() const;
        int size() const;

        class Iterator {
            friend class List<T>;
            public:
                T &operator*() const;

                Iterator &operator++();
                Iterator &operator--();

                bool operator==(const Iterator &other) const;
                bool operator!=(const Iterator &other) const;
                
            private:
                Iterator(Node *node);
                Node *node;
        };

        Iterator get_begin_iter() const;
        Iterator get_end_iter() const;

        void insert_before_iter(const Iterator &iter, const T v);
        void insert_after_iter(const Iterator &iter, const T v);

        void remove_at_iter(const Iterator &iter);

        // You technically don't need these, but they make things so much more
        // convenient.
        void insert_front(const T v);
        void insert_back(const T v);
        void remove_front();
        void remove_back();

        // This is useful for testing the linkage between nodes.
        void print_forwards_backwards();

    private:
        // A `List` has two pointers to `List::Node`s, called `head` and `tail`.
        Node *head; 
        Node *tail;
};

template <typename T>
List<T>::List() {
    head = new Node; 
    tail = new Node;

    head->next = tail;
    tail->prev = head;

    head->prev = nullptr;
    tail->next = nullptr;
}

template <typename T>
List<T>::~List() {
    while (!empty()) remove_front();
}

// ---

template <typename T>
bool List<T>::empty() const {
    return head->next == tail;
}

template <typename T>
int List<T>::size() const {
    int count = 0;

    for (Node *temp = head->next;
         temp != tail;
         temp = temp->next, count++);

    return count;
}

// ---

template <typename T>
T &List<T>::Iterator::operator*() const {
    return this->node->value;
}

template <typename T>
typename List<T>::Iterator &List<T>::Iterator::operator++() {
    this->node = this->node->next;
    return *this;
}

template <typename T>
typename List<T>::Iterator &List<T>::Iterator::operator--() {
    this->node = this->node->prev;
    return *this;
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator &other) const {
    return this->node == other.node;
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator &other) const {
    return this->node != other.node;
}

template <typename T>
List<T>::Iterator::Iterator(Node *node) {
    this->node = node;
}

// ---

template<typename T>
typename List<T>::Iterator List<T>::get_begin_iter() const {
    return Iterator(head->next);
}

template<typename T>
typename List<T>::Iterator List<T>::get_end_iter() const {
    return Iterator(tail);
}

template<typename T>
void List<T>::insert_before_iter(const Iterator &iter, const T v) {
    Node *tail_like = iter.node;

    Node *n = new Node;
    
    n->value = v;

    n->next = tail_like;
    n->prev = tail_like->prev;
    n->prev->next = n;
    tail_like->prev = n;

    return;
}

template<typename T>
void List<T>::insert_after_iter(const Iterator &iter, const T v) {
    Node *head_like = iter.node;

    Node *n = new Node;

    n->value = v;

    n->prev = head_like;
    n->next = head_like->next;
    n->next->prev = n;
    head_like->next = n;

    return;
}

template<typename T>
void List<T>::remove_at_iter(const Iterator &iter) {
    Node *to_remove = iter.node;

    Node *before = to_remove->prev;
    Node *after = to_remove->next;

    before->next = after;
    after->prev = before;

    delete to_remove;

    return;
}

template<typename T>
void List<T>::insert_front(const T v) {
    insert_before_iter(get_begin_iter(), v);
    return;
}

template<typename T>
void List<T>::insert_back(const T v) {
    insert_before_iter(get_end_iter(), v);
    return;
}

template<typename T>
void List<T>::remove_front() {
    remove_at_iter(get_begin_iter());
    return;
}

template<typename T>
void List<T>::remove_back() {
    remove_at_iter( --(get_end_iter()) );
    return;
}

// This is useful for testing the linkage between nodes.
template<typename T>
void List<T>::print_forwards_backwards() {

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

#endif
