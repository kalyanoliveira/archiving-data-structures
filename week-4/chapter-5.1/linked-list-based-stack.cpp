// A linked-list-based is kind of like a wrapper for a linked list.

// Which means that I have to first implement the very basics of a linked list
// here.

// That won't be too bad, though, since we'll only have to implement operations
// on the front of the linked list.

#include <iostream>

class Node {
    friend class LinkedList;

    private:
        int value;
        Node *next;
};

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();

        bool is_empty();

        void add_node_to_front(const int &v);
        void remove_frontal_node();

        void print();

        // This assumes that the user will not mess up and call this when the
        // list is empty.
        // Which is not great, but whatever.
        int get_frontal_node_value() const;

    private:
        Node *head; 
};

LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::~LinkedList() {
    while (!is_empty()) remove_frontal_node();
}

bool LinkedList::is_empty() {
    return head == NULL;
}

void LinkedList::add_node_to_front(const int &v) {
    // Create a new node in memory, and get a pointer to it:
    Node *new_node = new Node;

    // Assign the value of that new node.
    new_node->value = v;

    // Make the next of the new node be what head currently points to.
    new_node->next = head;

    // Make head point to the new node.
    head = new_node;
}

void LinkedList::remove_frontal_node() {
    // If the list is empty, simply return.
    if (is_empty()) return;

    // Get a pointer to the node that we need to delete, which is the node that
    // head points to.
    Node *node_to_delete = head;

    // Make head point to the next of the node_to_delete.
    head = node_to_delete->next;

    // Now we can just delete the node.
    delete node_to_delete;
}

void LinkedList::print() {
    std::cout << "LinkedList: " << std::endl;

    for (Node *temp = head; temp != NULL; temp=temp->next) {
        std::cout << temp->value << " ";
    }

    std::cout << std::endl;
}

// This assumes that the user will not mess up and call this when the
// list is empty.
// Which is not great, but whatever.
int LinkedList::get_frontal_node_value() const {
    return head->value;
}

class Stack {
    public:
        Stack();

        // We don't actually need a destructor, since the Stack class per se
        // does not allocate.
        //~Stack();

        bool is_empty() const;

        int size() const;

        void push(const int &v);

        void pop();

        int peek() const;

    private:
        LinkedList ll;
        int number_of_elements;
};

Stack::Stack() {
    number_of_elements = 0;
}

bool Stack::is_empty() const {
    return number_of_elements == 0;
}

int Stack::size() const {
    return number_of_elements;
}   

void Stack::push(const int &v) {
    ll.add_node_to_front(v);
    number_of_elements++;
}

void Stack::pop() {
    ll.remove_frontal_node();
    number_of_elements--;
}

int Stack::peek() const {
    if (is_empty()) {
        std::cout << "Peek: Stack is empty, returning -1" << std::endl;
        return -1;
    }

    return ll.get_frontal_node_value();
}

int main(void) {
    Stack s;

    s.push(10);
    s.push(11);

    std::cout << s.peek() << std::endl;

    s.pop();
    std::cout << s.peek() << std::endl;

    s.pop();
    std::cout << s.peek() << std::endl;

    return 0;
}
