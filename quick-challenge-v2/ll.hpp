#include <iostream>

class LinkedList {
    public:
        class Iterator;

        LinkedList();
        ~LinkedList();

        bool empty();
        int size();

        void push_front(int v);
        void pop_front();

        Iterator begin();
        Iterator end();

        void push_before(int v, Iterator& iter);
        void push_after(int v, Iterator& iter);

        void pop(Iterator& iter);
        void pop_before(Iterator& iter);
        void pop_after(Iterator& iter);

        void clear();

        void print();
        void print_backwards();

    private:
        class Node;

        Node* head;
        Node* tail;

        class Node {
            friend class LinkedList;
            public:
                int& operator*();
            private:
                Node(int v) : value(v), next(nullptr) {}
                int value; 
                Node* next;
        };

    public:
        class Iterator {
            friend class LinkedList;
            public:
                int& operator*();
                void operator++();
                void operator--();
                bool operator==(const Iterator& other);
                bool operator!=(const Iterator& other);
            private:
                Iterator(LinkedList& ll, Node* v) : _linkedlist(ll), node(v)  {}
                LinkedList& _linkedlist;
                Node* node;
        };
};
