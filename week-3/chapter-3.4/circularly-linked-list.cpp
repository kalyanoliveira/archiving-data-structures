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

        int get_back_node_value() const;
        int get_front_node_value() const;

        void print();

    private:
        // Notice that cursor simply points to a node.
        // The node that is pointed by cursor, though, is **not** a sentinel
        // node.
        CircularlyLinkedNode *cursor;
};

CircularlyLinkedList::CircularlyLinkedList() {
    cursor = NULL;
}

CircularlyLinkedList::~CircularlyLinkedList() {
    while(!empty()) { remove_node_after_cursor(); }
}

bool CircularlyLinkedList::empty() const {
    return cursor == NULL;
}

void CircularlyLinkedList::advance() {
    cursor = cursor->next;
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

void CircularlyLinkedList::remove_node_after_cursor() {
    // Create a pointer to the node that we have to delete.
    CircularlyLinkedNode *node_to_delete = cursor->next;

    // If we only have one node,
    if (node_to_delete->next == node_to_delete) {
        // Make the cursor NULL.
        cursor = NULL;

        // Now we can delete the node.
        delete node_to_delete;

        // And return.
        return;
    }

    // Make the next of the node pointed by cursor be the next of the node to
    // delete.
    cursor->next = node_to_delete->next;

    // Now we can delete the node.
    delete node_to_delete;
};

int CircularlyLinkedList::get_back_node_value() const {
    return cursor->value;
}

int CircularlyLinkedList::get_front_node_value() const {
    return cursor->next->value;
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

    std::cout << cll.get_back_node_value() << std::endl;
    std::cout << cll.get_front_node_value() << std::endl;
    
    cll.advance();
    cll.print();

    cll.remove_node_after_cursor();
    cll.print();

    cll.remove_node_after_cursor();
    cll.print();

    cll.remove_node_after_cursor();
    cll.print();

    return 0;
}
