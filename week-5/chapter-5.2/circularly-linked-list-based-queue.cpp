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

        // For a queue, this addition function is all that we really need.
        void insert_node_after_cursor(const int &v);

        // For a queue, this removal function is all that we really need.
        void remove_node_after_cursor();

        void advance_cursor();

        void print();

    private:
        Node* cursor;
};

CLL::CLL() {
    cursor = NULL;
}

CLL::~CLL() {
    while (!is_empty()) remove_node_after_cursor();
}

bool CLL::is_empty() const {
    return cursor == NULL;
}

void CLL::remove_node_after_cursor() {

    // Create a pointer to the node that we need to delete.
    Node *node_to_delete = cursor->next;

    // If we only have one node,
    if (node_to_delete->next = node_to_delete) {
        // Make the cursor point to nothing. After all, the list should be
        // empty after this.
        cursor = NULL;

        // Now we can free up our memory space.
        delete node_to_delete;

        // Terminate the function here.
        return;
    }

    // Make the next of the node pointed by the cursor be the next of the node
    // that we need to delete.
    cursor->next = node_to_delete->next;

    // Free up the memory space occupied by the node that we want to delete.
    delete node_to_delete;
}

void CLL::insert_node_after_cursor(const int &v) {
    // Create the new node in memory and obtain a pointer to it.
    Node *new_node = new Node;

    // Assign the value of that new node:
    new_node->value = v;
    
    // If the list is empty,
    if (is_empty()) {
        // We want to make the first node that we add to list point to itself.
        cursor = new_node;
        new_node->next = new_node;
    }

    // This means that the list is not empty.
    
    // Make the next of the new node be the next of the node pointed by the
    // cursor.
    new_node->next = cursor->next;

    // Make the next of the node pointed by the cursor be the new node.
    cursor->next = new_node;
}

int CLL::get_frontal_node_value() const {
    return (cursor->next)->value;
}

void CLL::advance_cursor() {
    if (is_empty()) return;
    cursor = cursor->next;
}

void CLL::print() {
    std::cout << "CircularlyLinkedList: ";

    if (!is_empty()) { 
        Node *temp = cursor;

        do {
            std::cout << temp->value << " ";
            temp = temp->next;
        } while (temp != cursor);
    }

    std::cout << std::endl;
}

class Queue {
    public:
        Queue();

        int size() const;

        bool is_empty() const;

        void enqueue(const int &v);
        void dequeue();

        int peek_front() const;

    private:
        CLL cll;
        int number_of_elements;
};

Queue::Queue() {
    number_of_elements = 0;
}

bool Queue::is_empty() const {
    return number_of_elements == 0;
}

void Queue::enqueue(const int &v) {
    // First, we need to insert the node in the CLL.
    cll.insert_node_after_cursor(v);

    // Then, we need to update our element count:
    number_of_elements++;  
   
    // Then, we need to advance our cursor.
    cll.advance_cursor();
}

void Queue::dequeue() {
    // If the queue is empty, abort.
    if (is_empty()) {
        std::cout << "Dequeue: Queue is currently empty, aborting..." << std::endl;
        return;
    }

    // Remove the frontal node in the CLL.
    cll.remove_node_after_cursor();

    // Decrease the element count.
    number_of_elements--;
}

int Queue::peek_front() const {
    if (is_empty()) {
        std::cout << "Peek front: Queue is currently empty, returning -1..." << std::endl;
        return -1;
    }

    return cll.get_frontal_node_value();
    
}

int main(void) {
    CLL cll;

    cll.insert_node_after_cursor(10);
    cll.insert_node_after_cursor(11);
    cll.insert_node_after_cursor(12);
    cll.print();

    cll.remove_node_after_cursor();
    cll.print();

    return 0;
}
