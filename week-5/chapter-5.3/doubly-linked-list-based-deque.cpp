// A `deque-ADT.md` can be implemented using doubly linked list!

#include <iostream>

class Node {
    friend class DLL;

    private:
        int value;
        Node *next;
};

class DLL {
    public:
        DLL();
        
        // // We must create a destructor because DLL allocates.
        // ~DLL();

        bool empty();

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
    tail->preve = head;

    // Make head and tail be the end of the linked list be ensuring NULL
    // pointers:
    head->prev = NULL;
    tail->next = NULL;
}

int main(void) {
    return 0;
}
