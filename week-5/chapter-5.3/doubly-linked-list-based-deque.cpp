// A `deque-ADT.md` can be implemented using doubly linked list!

#include <iostream>

class Node {
    friend class DLL;

    private:
        int value;
        Node *next;
        Node *prev;
};

class DLL {
    public:
        DLL();
        
        // We must create a destructor because DLL allocates.
        ~DLL();

        bool empty() const;

        void add_node_after_head(const int &v);
        void add_node_before_tail(const int &v);

        void remove_node_after_head();
        void remove_node_before_tail();

        void print() const;

    private:
        // These are sentinel nodes.
        Node *head;
        Node *tail;
};

DLL::DLL() {
    // Allocate two nodes, treat them as sentinels, and make head and tail
    // point to each of them.
    head = new Node;
    tail = new Node;

    // Make the head and tail sentinel nodes point to each other.
    head->next = tail;
    tail->prev = head;

    // Make head and tail be the end of the linked list be ensuring NULL
    // pointers:
    head->prev = NULL;
    tail->next = NULL;
}

DLL::~DLL() {
    while (!empty()) remove_node_after_head();
}

bool DLL::empty() const {
    return head->next == tail;
}

void DLL::add_node_after_head(const int &v) {
    Node *new_node = new Node;
    new_node->value = v;

    // Make the next of the new node be the next of the node pointed by head.
    new_node->next = head->next;

    // Make the prev of the next of the node pointed by head by the new node.
    // == this is the only place where all of this could not work lol ==
    (head->next)->prev = new_node;

    // Make the prev of the new_node be the node pointed by head.
    new_node->prev = head; 

    // Make the next of the node pointed by head be the new node.
    head->next = new_node;
}

void DLL::add_node_before_tail(const int &v) {
    Node *new_node = new Node;
    new_node->value = v;

    // Make the prev of the new node be the prev of the node pointed by tail;
    new_node->prev = tail->prev;

    // Make the next of the new node by the tail;
    new_node->next = tail;

    // Make the next of the prev of the node pointed by tail be the new node.
    (tail->prev)->next = new_node;

    // Make the prev of the tail be the new node;
    tail->prev = new_node;
}

void DLL::remove_node_after_head() {
    Node *node_to_remove = head->next;

    // Make the next of the node pointed by head by the next of the
    // node_to_delete.
    head->next = node_to_remove->next;

    // Make the prev of next of the node_to_remove be the head.
    (node_to_remove->next)->prev = head;

    delete node_to_remove;
}

void DLL::remove_node_before_tail() {
    Node *node_to_remove = tail->prev;

    // Make the prev of the node pointed by tail be the prev of the
    // node_to_delete.
    tail->prev = node_to_remove->prev;

    // Make the next of the prev of the node_to_delete be the tail.
    (node_to_remove->prev)->next = tail;

    delete node_to_remove;
}

void DLL::print() const {
    std::cout << "DLL: ";

    for (Node *temp = head->next; temp->next != NULL; temp=temp->next) {
        std::cout << temp->value << " ";
    }

    std::cout << std::endl;
}

int main(void) {
    DLL dll;

    dll.add_node_after_head(1);
    dll.add_node_after_head(2);
    dll.add_node_after_head(3);
    dll.print();

    dll.add_node_before_tail(1);
    dll.add_node_before_tail(2);
    dll.add_node_before_tail(3);
    dll.print();

    dll.remove_node_after_head();
    dll.remove_node_before_tail();
    dll.print();

    return 0;
}
