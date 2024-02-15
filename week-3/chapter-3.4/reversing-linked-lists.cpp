// Let A equal a linked list.
// Let B equal a buffer linked list.
// We can reverse A by repeatedly extracting each first-node of A into B.
// Then, we repeatedly extract each last-node of B into A.

#include <iostream>

// Implement a normal node class.
class Node {
    friend class LinkedList;

    private:
        int value;
        Node *next;
};

// Implement a Linked List with push/pop from head/tail.
class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        
        bool is_empty() const;

        void print() const;

        // This next four signatures should be the entire interface that we
        // need to realize reversing thing.
        void add_node_to_beginning(const int &v);
        void add_node_to_end(const int &v);

        void remove_first_node();
        void remove_last_node();

    private:
        Node *head;
};

LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::~LinkedList() {
    while (!is_empty()) { remove_first_node(); }
}

bool LinkedList::is_empty() const {
    return head == NULL;
}

void LinkedList::print() const {
    std::cout << "LinkedList: ";

    if (!is_empty()) {
        for (Node *temp = head; temp != NULL; temp=temp->next) {
            std::cout << temp->value << " ";
        }
    }

    std::cout << std::endl;
}

void LinkedList::add_node_to_beginning(const int &v) {
    // Create a new node in memory, and a pointer to it.
    Node *new_node = new Node;

    // Assign the value of that new node.
    new_node->value = v;
    
    // Make the next of the new node be what head points to.
    // There are no sentinels nodes in a singly linked list, hence we can
    // just treat the node that head points to as the first node.
    new_node->next = head;

    // Make head point to the new node.
    head = new_node;
}

void LinkedList::add_node_to_end(const int &v) {
    // Let's do the whole "new node creation" process shabang.
    // First, we allocate some space in memory for a new node, and get a
    // pointer to it.
    Node *new_node = new Node;
    // Then we assing the value of that new node:
    new_node->value = v;

    // The new_node should be the end of the list, hence the next of new_node
    // should be NULL:
    new_node->next = NULL; 

    // Now, we have to find the actual last node of the list.
    Node *last_node;

    // If the list is not empty,
    if (!is_empty()) {
        for (
            last_node = head; 
            // The last node in the linked list points to NULL.
            last_node->next != NULL;
            last_node = last_node->next
        );

        // Now that we have the last node of the list, we just have to make the
        // next of the last node be the new node.
        last_node->next = new_node;
        
        
    } else {
        // This means that the list is empty. We just need to make head point
        // to the new node.
        head = new_node;
    }

    return;
}

void LinkedList::remove_first_node() {
    // If the list is empty, there is nothing to remove.
    if (is_empty()) return;

    // This means that the list is not empty.
    // Create a pointer to the node that we need to delete, which is the node
    // pointed by head:
    Node *node_to_delete = head;

    // Make head point to the next of our node that we have to delete:
    head = node_to_delete->next;

    // Delete the node (lol this is so simple):
    delete node_to_delete;
    
}

void LinkedList::remove_last_node() {
    // If the list is empty, there is nothing to do:
    if (is_empty()) return;

    // Now, we need to find the last node, and the node before it.
    
    // We initialize the second to last node to NULL our linked list may have
    // only one node.
    Node *second_to_last_node = NULL;

    // We'll initially say that the last node is the node pointed by head, and
    // move it further down the list if that is not case.
    Node *last_node = head;

    for(;
        // We need to stop running the loop if we reach the last node.
        // The last node is the node with `next` equal to NULL.
        // Hence, we keep running the loop is `last_node->next` does not equal
        // NULL.
        last_node->next != NULL;
        // Here, we just move both of our pointers.
        second_to_last_node = last_node, last_node=last_node->next
    );

    // Notice how, by the end of this for loop, if `second_to_last_node` still
    // equals NULL, then that means that our linked list has only one node.
    // In this edge case, removal is quite simple:
    if (second_to_last_node == NULL) {
        // Make head point to NULL.
        head = NULL;
        // Free up the memory space.
        delete last_node;
        // Stop the function here.
        return;
    }

    // This means that have at least two nodes.
    // Make the second to last node point to NULL.
    second_to_last_node->next = NULL;

    // Free up the memory space.
    delete last_node;
}

int main(void) {
    LinkedList ll;

    ll.add_node_to_beginning(10);
    ll.add_node_to_beginning(11);
    ll.add_node_to_beginning(12);
    ll.add_node_to_beginning(13);
    ll.add_node_to_beginning(14);

    ll.add_node_to_end(10);
    ll.add_node_to_end(11);
    ll.add_node_to_end(12);
    ll.add_node_to_end(13);
    ll.add_node_to_end(14);

    ll.print();

    ll.remove_first_node();
    ll.remove_first_node();

    ll.remove_last_node();
    ll.remove_last_node();

    ll.print();

    return 0;
}
