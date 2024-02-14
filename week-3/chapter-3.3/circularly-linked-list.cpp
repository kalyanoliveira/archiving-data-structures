// In a circularly linked list, we have a cursor node that points to any random
// node in the list.
// The node pointed by the cursor is known as the back element.
// The node after the node pointed by the cursor is known as the front element. 

#include <iostream>

class CircularlyLinkedNode {
    friend class CircularlyLinkedList;

    private:
        int value;
        CircularlyLinkedNode *next;
};

class CircularlyLinkedList {
    public:
        CircularlyLinkedList();
        ~CircularlyLinkedList();

        bool empty() const;

        void advance();

        void add_node_after_cursor(const int &v);
        void remove_node_after_cursor();

        const CircularlyLinkedNode &get_back_node() const;
        const CircularlyLinkedNode &get_front_node() const;

    private:
        CircularlyLinkedNode *cursor;
};

void CircularlyLinkedList::CircularlyLinkedList() {
    cursor->next = NULL;
}

bool CircularlyLinkedList::empty() const {
    cursor->next == NULL;
}

int main(void) {
    return 0;
}