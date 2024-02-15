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

        int get_node_after_head() const;
        int get_node_before_tail() const;

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
    if (empty()) return;

    Node *node_to_remove = head->next;

    // Make the next of the node pointed by head by the next of the
    // node_to_delete.
    head->next = node_to_remove->next;

    // Make the prev of next of the node_to_remove be the head.
    (node_to_remove->next)->prev = head;

    delete node_to_remove;
}

void DLL::remove_node_before_tail() {
    if (empty()) return;

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

int DLL::get_node_after_head() const {
    if (empty()) return -1;
    return head->next->value;
}

int DLL::get_node_before_tail() const {
    if (empty()) return -1;
    return tail->prev->value;
}

class Deque {
    public:
        Deque();
        
        // No destructor since deque itself does not allocate.
        // ~Deque();
        
        bool empty() const;

        int size() const;

        void push_front(const int &v);
        void push_back(const int &v);

        void remove_front();
        void remove_back();

        int get_front() const;
        int get_back() const;
    
    private:
        DLL dll;
        int number_of_elements;
};

Deque::Deque() {
    number_of_elements = 0;
}

bool Deque::empty() const {
    return number_of_elements == 0;
}

int Deque::size() const {
    return number_of_elements;
}

void Deque::push_front(const int &v) {
    dll.add_node_after_head(v);
    number_of_elements++;
}

void Deque::push_back(const int &v) {
    dll.add_node_before_tail(v);
    number_of_elements++;
}

void Deque::remove_front() {
    if (empty()) return;

    dll.remove_node_after_head();
    number_of_elements--;
}

void Deque::remove_back() {
    if (empty()) return;

    dll.remove_node_before_tail();
    number_of_elements--;
}

int Deque::get_front() const {  
    if (empty()) return -2;

    return dll.get_node_after_head();
}

int Deque::get_back() const {
    if (empty()) return -2;

    return dll.get_node_before_tail();
}

int main(void) {
    Deque deck;
    
    deck.push_front(1);
    deck.push_front(2);
    deck.push_back(7);
    std::cout << deck.get_front() << std::endl;

    deck.remove_front();
    std::cout << deck.get_front() << std::endl;

    deck.remove_front();
    std::cout << deck.get_front() << std::endl;

    deck.remove_front();
    std::cout << deck.get_front() << std::endl;
    

    return 0;
}
