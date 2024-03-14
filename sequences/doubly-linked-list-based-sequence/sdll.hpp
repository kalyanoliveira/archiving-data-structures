// Overall, this entire implementation is very fragile, because we do not make
// sure that no dangling pointers exist, or that only valid indices are being
// passed.
// I guess it is up to the user to make sure that those scenarios do not occur
// you know.


#ifndef SEQUENCED_DOUBLY_LINKED_LIST_H
#define SEQUENCED_DOUBLY_LINKED_LIST_H

class SequencedDLL {
private:
    struct Node {
        int value;
        Node *next;
        Node *prev;
    };

public:
    SequencedDLL();
    ~SequencedDLL();

    bool empty() const;
    int size() const;

    class SDLLIterator {
        friend class SequencedDLL;

        public:
            // Returns a reference to the integer of the node located at this
            // position.
            int &operator*() const;

            bool operator==(const SDLLIterator &other) const;
            bool operator!=(const SDLLIterator &other) const;

            // Moves the position one unit forwards.
            SDLLIterator &operator++();
            // Moves the position one unit backwards.
            SDLLIterator &operator--();
        
        private:
            // The private constructor take in a pointer to a node.
            SDLLIterator(Node *n);
            // Every iterator holds a pointer to a node.
            Node *node;
    };

    // Returns an iterator pointing to the node after the sentinel header node.
    SDLLIterator begin() const;
    // Returns an iterator pointing to the sentinel tail node.
    SDLLIterator end() const;

    void insert_before(const SDLLIterator &position, const int v);
    void insert_after(const SDLLIterator &position, const int v);

    void remove(const SDLLIterator &position);

    SDLLIterator find_iter_at_index(const int i) const;
    int find_index_of_iter(const SDLLIterator &iter) const;

    void front_insert(const int v);
    void back_insert(const int v);

    void front_remove();
    void back_remove();

    void print() const;

private:
    Node *head;
    Node *tail;

};

#endif
