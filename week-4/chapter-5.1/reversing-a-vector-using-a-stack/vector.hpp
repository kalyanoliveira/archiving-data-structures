#ifndef VECTOR_H
#define VECTOR_H

// Let's do an array-based Vector!
// This is not going to be that fun.
// (after implementing): it was not that bad!

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
        void erase(const int index);

        void resize(const int c);

        void print() const;

    private:
        int n;
        int *a;
        int capacity;
};

#endif
