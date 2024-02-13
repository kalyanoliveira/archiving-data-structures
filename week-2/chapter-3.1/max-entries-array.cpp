// Here, we'll create class that manages adding only the highest values to a
// dynamic array.

#include <iostream>

// First, we define a class for a generic entry in our array called `Entry`:
class Entry {
    public:
        Entry(const int &v = 10);
        int get_entry_value() const;

    private:
        int entry_value;
};

Entry::Entry(const int &v) {
    entry_value = v;
}

int Entry::get_entry_value() const {
    return entry_value;
}

// Now, we are going to define the class that manages this array of `Entry`
// objects:
class MaxEntries{
    public:
        MaxEntries(const int &m);

        void add_entry(const Entry &e);

        void remove_entry_at_index(const int &i);

    private:
        Entry *entries;
        int max_number_entries;
        int current_number_entries;
};

MaxEntries::MaxEntries(const int &m) {
    max_number_entries = m;
    entries = new Entry[m];
    current_number_entries = 0;
}

// void add_entry(const Entry &e) {
//     // If we currently have less entries than the max, just append the new
//     // entry `e` to our array.
//     if (current_number_entries < max_number_entries) {
//         entries[current_entries + 1] = e;
//     }
// 
//     // If we have the max amount of possible entries, we need to first figure out if `e` is more than any of the `Entry` objects currently in our entries array.
// }

int main(void) {

    return 0;
}
