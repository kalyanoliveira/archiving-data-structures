#ifndef ITERATED_DOUBLY_LINKED_LIST_H 
#define ITERATED_DOUBLY_LINKED_LIST_H

#include <stdexcept>
#include <string>

class OutOfBoundsException : public std::runtime_error {
    OutOfBoundsException(const std::string &msg = "Out of bounds exception") :
        std::runtime_error(msg) {}
};

class EmptyException : public std::runtime_error {
    EmptyException(const std::string &msg = "Empty exception") :
        std::runtime_error(msg) {}
};

class IteratedDLL {
    private:
        struct Node {
            int value;
            Node *next;
            Node *prev;
        };

    public:
        IteratedDLL();
        ~IteratedDLL();

        bool empty() const;
        int size() const;

        // Convenience methods.
        // It would be intersting to implement these methods using the
        // iterator methods that we already have.
        // Inserts node with value v in the front of the list.
        void insert_front(const int v);
        // Inserts node with value v to the back of the list.
        void insert_back(const int v);
        // Removes the node in the front of the list.
        void remove_front();
        // Removes the node in the back of the list.
        void remove_back();

        class Iterator {
            friend class IteratedDLL;
            public:
                int &operator*();
                
                bool operator==(const Iterator &other) const;
                bool operator!=(const Iterator &other) const;

                // These are actually so clutch.
                // They are essentially what gives the Iterator its "iterating" capabilities.
                Iterator &operator++();
                Iterator &operator--();
                    
            private:
                Iterator(Node *node);
                Node *internal_node;
        };

        // Returns an iterator set to the first position of the list (i.e. the
        // node after the "head" sentinel node).
        Iterator get_first_iterator();
        // This returns an iterator to the position *after* the last entry on
        // the list (i.e. the "tail" sentinel node).
        Iterator get_last_iterator();

        // Inserts a node before the position of an Iterator.
        void insert_before(const Iterator &i, const int v);
        // Inserts a node after the position of an Iterator.
        void insert_after(const Iterator &i, const int v);

        void remove(Iterator &i);

        void print() const;

    private:
        Node *head;
        Node *tail;
        
};

#endif
