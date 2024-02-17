// DL stands for "Doubly Linked."

#ifndef DLL_NODE_H
#define DLL_NODE_H

class DLNode {
    friend class DLL;

    private:
        char value;

        // Doubly-linked nodes have both a next *and a prev*.
        DLNode *next;
        DLNode *prev;
};

#endif
