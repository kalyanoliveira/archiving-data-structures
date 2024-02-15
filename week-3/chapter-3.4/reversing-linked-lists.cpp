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
        //~LinkedList();
        
        bool is_empty() const;

        void print() const;

        void add_node_to_beginning(const int &v);
        void add_node_to_end(const int &v);

    private:
        Node *head;
};

LinkedList::LinkedList() {
    head = NULL;
}

bool LinkedList::is_empty() const {
    return head == NULL;
}

void LinkedList::print() const {
    std::cout << "LinkedList: ";

    if (!is_empty()) {
        for (Node *temp = head; temp->next != NULL; temp=temp->next) {
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

int main(void) {
    LinkedList ll;

    ll.add_node_to_beginning(10);
    ll.add_node_to_beginning(11);
    ll.add_node_to_beginning(12);
    ll.add_node_to_beginning(13);
    ll.add_node_to_beginning(14);

    // ll.add_node_to_end(10);
    // ll.add_node_to_end(11);
    // ll.add_node_to_end(12);
    // ll.add_node_to_end(13);
    // ll.add_node_to_end(14);

    ll.print();

    return 0;
}
