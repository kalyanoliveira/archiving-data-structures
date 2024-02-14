// Central to doubly linked lists is the concept of "sentinel nodes."

// Sentinel nodes do not hold any meaningful values. Yes, they are nodes, but
// we simply use them to demarcate part of our list.

// In a doubly linked list, we have two sentinels nodes: 
// 1. one at the beginning, called the head;
// 2. and one at the end, called the tail.

#include <iostream>

// Nodes of a doubly linked list are called Doubly Linked Nodes.
class DoublyLinkedNode {
    friend class DoublyLinkedList;

    private:
        int value;
        // They are doubly linked because they have both a `next` and `prev`.
        DoublyLinkedNode *next;
        DoublyLinkedNode *prev;
};

class DoublyLinkedList {
    public:
        DoublyLinkedList();

        // Since we allocate memory, we should also have a constructor here.
        // ~DoublyLinkedList();
        
        bool empty() const;

        void add_node_to_head(const int &v);
        void add_node_to_tail(const int &v);

        void remove_node_from_head();
        void remove_node_from_tail();

        void print_forwards_backwards();

    private:
        DoublyLinkedNode *head;
        DoublyLinkedNode *tail;
};

DoublyLinkedList::DoublyLinkedList() {
	// For initialization, we should be making two sentinel nodes: head and tail.
	// They should also point to each other.
	// Head always has NULL prev.
	// And tail always has NULL next.
	head = new DoublyLinkedNode;
	tail = new DoublyLinkedNode;
    head->next = tail;
}

// Define the destructor here latter ig.
// DoublyLinkedList::~DoublyLinkedList() {
// }

bool DoublyLinkedList::empty() const {
    return head->next == tail;
}

void DoublyLinkedList::add_node_to_head(const int &v) {
    // Create a new node.
    DoublyLinkedNode *new_node = new DoublyLinkedNode;

    // Set the value of that new node:
    new_node->value = v;

    // Make the next of the new node point to the next of head.
    new_node->next = head->next;

    // Make the prev of the next of the new node point to the new node.
    (new_node->next)->prev = new_node;

    // Make the prev of the new node by the head.
    new_node->prev = head;

    // Make the next of head by the new node.
    head->next = new_node;
}

void DoublyLinkedList::add_node_to_tail(const int &v) {
    // Create a new node.
    DoublyLinkedNode *new_node = new DoublyLinkedNode;

    // Set the value of that node:
    new_node->value = v;

    // Make the next of the prev of tail be the new node.
    (tail->prev)->next = new_node;

    // Make the prev of the new node be the prev of tail.
    new_node->prev = tail->prev;

    // Make the next of the new node be the tail.
    new_node->next = tail;

    // Make the prev of tail be the new node.
    tail->prev = new_node;
}

// Here, we are printing forwards and backwards to test the doubly-linked
// characteristic of this list.
void DoublyLinkedList::print_forwards_backwards() {
    std::cout << "DoublyLinkedList: ";

    // Start at the first node, stop once we reach the tail node.
    for (DoublyLinkedNode *temp = head->next; temp->next != NULL; temp=temp->next) {
        std::cout << temp->value << " ";
    }

    std::cout << std::endl;
}

void DoublyLinkedList::remove_node_from_head() {
    if (empty()) return;

    // Create a pointer to the node that we need to remove:
    DoublyLinkedNode *node_to_remove = head->next;

    // Make the next of head be the next of the node for removal.
    head->next = node_to_remove->next;

    // Make the prev of the next of node for removal be the head.
    (node_to_remove->next)->prev = head;

    // Now we should just be able to free the space in memory.
    delete node_to_remove;
}

void DoublyLinkedList::remove_node_from_tail() {
    if (empty()) return;

    // Create a pointer to the node that we need to remove.
    DoublyLinkedNode *node_to_remove = tail->prev;

    // Make the next of the prev of the node to remove the tail.
    (node_to_remove->prev)->next = tail;

    // Make the prev of the tail be the prev of the node to remove.
    tail->prev = node_to_remove->prev;

    // Now we can free up our space.
    delete node_to_remove;
}

int main(void) {
    DoublyLinkedList dll;

    dll.add_node_to_head(7);
    dll.add_node_to_head(11);
    dll.add_node_to_head(13);
    dll.add_node_to_head(15);

    dll.add_node_to_tail(7);
    dll.add_node_to_tail(11);
    dll.add_node_to_tail(13);
    dll.add_node_to_tail(15);

    dll.print_forwards_backwards();

    dll.remove_node_from_head();
    dll.remove_node_from_tail();
    dll.print_forwards_backwards();

    dll.remove_node_from_head();
    dll.remove_node_from_tail();
    dll.print_forwards_backwards();

    return 0;
}
