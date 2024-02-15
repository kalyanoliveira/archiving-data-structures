// Here, we'll include the implementation of a queue using a circularly linked
// list.

// Which means that I need to implement that first.

#include <iostream>

class Node {
    friend class CLL;

    private:
        int value;
        Node *next;
};

// CLL for CircularlyLinkedList.
class CLL {
    public:
        CLL();
        ~CLL();

        bool is_empty() const;

        int get_frontal_node_value() const;
        int get_rear_node_value() const;

        // For a queue, this addition function is all that we really need.
        void insert_node_after_cursor();

        // For a queue, this removal function is all that we really need.
        void remove_node_after_cursor();

    private:
        Node* cursor;
};

int main(void) {
    return 0;
}
