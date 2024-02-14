// Here, we'll do a simple, singly linked list.

#include <iostream>

class Node {
    // Let's make a `SinglyLinkedList` a friend of `Node`.
    // This avoids writing getters:
    friend class SinglyLinkedList;

    private:
        // Every node has
        // a value...
        int value;
        // ... and a pointer to a "next" node.
        Node *next;
};

class SinglyLinkedList {
    public:
        SinglyLinkedList();
        // Since we are allocating memory, we need to create a destructor.
        ~SinglyLinkedList();

        // Let's create two basic operation functions:
        // adding a node to the front of the list (i.e., after head), and...
        void add_node_to_front(int value);
        // ... removing the node in the front of the list (i.e. the node after
        // head).
        void remove_front_node();

        // We can also just create a simply inline function that just tells us
        // if the list is empty or not.
        bool empty() const;

        void print();

    private:
        Node *head;
};

// In the constructor of our singly linked list, we need to make head point to
// NULL:
SinglyLinkedList::SinglyLinkedList() {
    head = NULL;
}

bool SinglyLinkedList::empty() const {
    return head == NULL;
}

// In the destructor, we are supposed to remove the front node while the list
// is not `empty()`.
SinglyLinkedList::~SinglyLinkedList() {
    while (!empty()) { remove_front_node(); }
}

void SinglyLinkedList::add_node_to_front(int v) {
    // Create a new node.
    Node *new_node = new Node;

    // Assign the value of that new node:
    new_node->value = v;

    // Assign the next of that new node, which should be what head is currently
    // pointing to:
    new_node->next = head;

    // Make head point to this new node:
    head = new_node;

    return;
}

void SinglyLinkedList::remove_front_node() {
    // Create a pointer to the node that we need to delete.
    Node *node_to_delete = head;

    // Make head point to the `next` of the node that we need to delete.
    head = node_to_delete->next;

    // Free the node that we need to delete.
    delete node_to_delete;
}

void SinglyLinkedList::print() {
    std::cout << "SinglyLinkedList: ";

    // Create a temporary `Node` pointer to the head of the list.
    for (Node *temp = head; temp != NULL; temp=temp->next) {
        std::cout << temp->value << " ";
    }
    
    std::cout << std::endl;
}

int main(void) {
    SinglyLinkedList sll;

    sll.add_node_to_front(7);
    sll.add_node_to_front(8);
    sll.add_node_to_front(9);

    sll.print();

    return 0;
}
