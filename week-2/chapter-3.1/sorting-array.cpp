// In this file, we'll create a dynamic array wrapped by a class, a function
// that adds elements to that array, and a function that sorts the array.

#include <iostream>

class Entry {
    public:
        Entry(const int &v = 0);

        int get_value() const;

    private:
        int value;
};

Entry::Entry(const int &v) {
    value = v;
}

int Entry::get_value() const {
    return value;
}

class Entries {
    public:
        Entries(const int &c);

        void add_entry_to_end(const Entry &e);

        void sort();

        void print();

    private:
        int capacity;
        Entry *a;
        int current_number_entries;
};

Entries::Entries(const int &c) {
    capacity = c;
    current_number_entries = 0;
    a = new Entry[c];
}

int main(void) {
    Entry e;
    std::cout << e.get_value() << std::endl;
        
    return 0;
}
