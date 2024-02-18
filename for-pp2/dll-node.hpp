// DL stands for "Doubly Linked."

#ifndef DLL_NODE_H
#define DLL_NODE_H

#include <string>

class DLNode {
    friend class DLL;

    private:
        std::string value;

        // Doubly-linked nodes have both a next *and a prev*.
        DLNode *next;
        DLNode *prev;
};

#endif
