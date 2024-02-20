// In the spirit of encapsulation, well define a `Position` class, which'll be
// a wrapper around any node in our tree.

// Let's define its informal interface here:

#ifndef POSITION_INTERFACE_H
#define POSITION_INTERFACE_H

class PositionInterface {
    public:
        // This should not be constant: we want our dereferencing operation to
        // return something with which we can both read and write.
        virtual int operator*() = 0;
        virtual PositionInterface get_parent() const = 0;
        virtual PositionInterface get_child() const = 0;
        virtual bool is_root() const = 0;
        virtual bool is_leaf() const = 0;
};

#endif
