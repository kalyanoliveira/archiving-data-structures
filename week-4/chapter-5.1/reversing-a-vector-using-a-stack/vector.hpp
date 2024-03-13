#ifndef VECTOR_H
#define VECTOR_H

#include "index-exception.hpp"

// Let's do an array-based Vector!
// This is not going to be that fun.

class Vector {
    public:
        Vector();
        Vector(const int c);
        ~Vector();

        bool empty() const;
        int size() const;

        int at(const int index) const;
        void set(const int index, const int element);
        void insert(const int index, const int element);

        void resize(const int c);

    private:
        int n;
        int *a;
        int capacity;
};

#endif
