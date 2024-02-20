// Here, we'll define an informal interface for our tree.

#ifndef TREE_INTERFACE_H
#define TREE_INTERFACE_H

#include "position-interface.hpp"

#include "position-list-interface.hpp"

class TreeInterface {
    public:
        virtual int size() const = 0;
        virtual bool empty() const = 0;
        virtual PositionInterface get_root() const = 0;
        virtual PositionListInterface get_positions() const = 0;
};

#endif
