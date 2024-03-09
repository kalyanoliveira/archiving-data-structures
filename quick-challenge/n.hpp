#ifndef NODE_H
#define NODE_H

class Node {
    friend class LinkedList;
    private:
        int value;
        Node *next;
};

#endif
