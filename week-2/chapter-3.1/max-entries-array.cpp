// Here, we'll create class that manages adding only the highest values to a
// dynamic array.

#include <iostream>

// First, we define a class for a generic entry in our array called `Entry`:
class Entry {
    public:
        // Every entry is initialized to 0 by default.
        Entry(const int &v = 0);

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
        // Specify a constructor, which takes in the maximum possible number of
        // entries.
        MaxEntries(const int &m);

        // Since `MaxEntries` allocates, it makes sense for us to define a
        // destructor too.
        ~MaxEntries();

        // Specify an entry-adding function.
        void add_entry(const Entry &e);

        // Declare an entry-removing function by means of index.
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

MaxEntries::~MaxEntries() {
    delete [] entries;
}

void MaxEntries::add_entry(const Entry &e) {
    // If we currently have less entries than the max,
    if (current_number_entries < max_number_entries) {
        // Append the new entry.
        entries[current_number_entries + 1] = e;
        // Update the entry count.
        current_number_entries += 1;
        // Finish the addition process.
        return;
    }

    // This means we have the max amount of possible entries.
    
    // Initialize a "smaller entries" count.
    int smaller_entries = 0;
    // Initialize a "first small entry" index to -1 (because 0 is also valid
    // index).
    int first_small_entry = -1;

    // For each current entry:
    for (int i = 0; i < current_number_entries; i++) {
        const Entry &curr_entry = entries[i];

        // If that entry is less than the new entry
        if (curr_entry.get_entry_value() < e.get_entry_value()) {
            // Add to smaller entries
            smaller_entries++;
            // If first small entry index == -1, update it.
            if (first_small_entry = -1) first_small_entry = i;
        }
    }

    // If there are no smaller entries, return.
    if (smaller_entries == 0) return;

    // Figure out the index of the smaller entry to remove.
    int index_to_remove = (first_small_entry + smaller_entries) - 1;

    // Make a call to the remove function.
}

int main(void) {
    
    // Instantiate a new `MaxEntries` object by specifying the maximum possible
    // number of entries.
    MaxEntries m_es(10);

    return 0;
}
