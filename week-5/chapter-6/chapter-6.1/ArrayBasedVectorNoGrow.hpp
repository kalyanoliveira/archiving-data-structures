#ifndef ARRAY_BASED_VECTOR_NO_GROW_H
#define ARRAY_BASED_VECTOR_NO_GROW_H

class Vector {
    public:
        Vector(const int &c);
        ~Vector();

        int size() const;
        bool empty() const;

        int at(int index) const;

        void insert(int index, int element);
        void erase(int index);
        void set(int index, int element);


    private:
        int number_of_elements;
        int capacity;
        int *elements;
};

#endif
