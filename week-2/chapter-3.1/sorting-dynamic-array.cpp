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
        Entry *entries;
        int current_number_entries;
};

Entries::Entries(const int &c) {
    capacity = c;
    current_number_entries = 0;
    entries = new Entry[c];
}

void Entries::add_entry_to_end(const Entry &e) {
    // If the array is currently full,
    if (current_number_entries == capacity) {
        // Just substitute the last entry by the new one.
        entries[capacity - 1] = e;
        // And then return;
        return;
    }

    // This means that array is not full.
    // So let's just add the new entry to the last available spot, and...
    entries[current_number_entries] = e;
    // ... increase the number of entries.
    current_number_entries++;
}

void Entries::sort() {
    // Sort an array of only `sub_size` entries.
    int sub_size = 2;

    // While the subsize is not larger than the total size of the array,
    while (sub_size <= current_number_entries) {
        int last_entry_index = sub_size - 1;
        
        // Save the value of the last entry so that we do not loose it during
        // shifts.
        int last_entry_value = entries[last_entry_index].get_value();

        // This value will store the index of an entry that we could
        // potentially shift rightwards in the array.
        int next_shift_index = last_entry_index - 1;

        // While the index of an entry that we could potentially shift is not
        // less than zero,
        // AND
        // the entry located at the index that we could potentially shift has a
        // larger value than the last entry in the sub-sized array,
        while (next_shift_index >= 0 && entries[next_shift_index].get_value() > last_entry_value) {
            entries[last_entry_index] = entries[next_shift_index];
            last_entry_index = next_shift_index;
            next_shift_index--;
        }

        // This should create an empty insertion spot for our initial last
        // entry, the one we saved the value for.
        // This insertion spot should be located in `next_shift_index + 1`
        // because our previous while loop decrease next_shift_index by 1.
        entries[next_shift_index + 1] = Entry(last_entry_value);
    
        // Increase the size of the array that we are sorting.
        sub_size++;
    }
}

void Entries::print() {
    std::cout << "Entries: ";
    for (int i = 0; i < current_number_entries; i++) {
        std::cout << entries[i].get_value() << " ";
    }

    std::cout << std::endl;
}

int main(void) {
    Entries es(10);
    
    Entry e(7);
    es.add_entry_to_end(e);

    e = Entry(5);
    es.add_entry_to_end(e);

    e = Entry(3);
    es.add_entry_to_end(e);

    e = Entry(1);
    es.add_entry_to_end(e);
    es.print();

    es.sort();
    es.print();

    return 0;
}
