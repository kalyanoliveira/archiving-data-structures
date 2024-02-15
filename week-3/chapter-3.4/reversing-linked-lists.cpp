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

        void add_node_after_head(const int &v);
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

void LinkedList::add_node_after_head(const int &v) {
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

void add_node_to_end(const int &v) {
    // Let's do the whole "new node creation" process shabang.
    return
}

int main(void) {
    LinkedList ll;

    ll.add_node_after_head(10);
    ll.add_node_after_head(11);
    ll.add_node_after_head(12);
    ll.add_node_after_head(13);
    ll.add_node_after_head(14);

    ll.print();

    return 0;
}
