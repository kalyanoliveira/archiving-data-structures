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
        //~CircularlyLinkedList();

        bool empty() const;

        void advance();

        void add_node_after_cursor(const int &v);
        void remove_node_after_cursor();

        const CircularlyLinkedNode &get_back_node() const;
        const CircularlyLinkedNode &get_front_node() const;

        void print();

    private:
        CircularlyLinkedNode *cursor;
};

CircularlyLinkedList::CircularlyLinkedList() {
    cursor = NULL;
}

// void CircularlyLinkedList::~CircularlyLinkedList() {
// }

bool CircularlyLinkedList::empty() const {
    return cursor == NULL;
}

void CircularlyLinkedList::add_node_after_cursor(const int &v) {
    // Create a new node
    CircularlyLinkedNode *new_node = new CircularlyLinkedNode;

    // Assign the value of that new node.
    new_node->value = v;

    // If the list is empty,
    if (empty()) {
        // Make the cursor point to that node.
        cursor = new_node;

        // Make the next of that new node be itself.
        new_node->next = new_node;

        // Return.
        return;
    }

    // This means that the list is not empty.
    // Make the next of the new node by the next of the cursor.
    new_node->next = cursor->next;    

    // Make the next of the cursor be the new node.
    cursor->next = new_node;
}

void CircularlyLinkedList::print() {
    std::cout << "CircularlyLinkedList: ";

    if (!empty()) { 
        CircularlyLinkedNode *temp = cursor;

        do {
            std::cout << temp->value << " ";
            temp = temp->next;
        } while (temp != cursor);
    }

    std::cout << std::endl;
}

int main(void) {
    CircularlyLinkedList cll;    

    cll.add_node_after_cursor(7);
    cll.add_node_after_cursor(8);
    cll.add_node_after_cursor(9);

    cll.print();

    return 0;
}
