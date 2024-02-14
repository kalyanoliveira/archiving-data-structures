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

        void print();

    private:
        // This array goes from highest entry value to lowest entry value.
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
    // If the list of entries is empty and we have not reached the maximum
    // number of entries,
    if (current_number_entries == 0 && current_number_entries != maximum_number_entries) {
        // Add the new entry to our array.
        entries[0] = e;
        // Increase entry count.
        current_number_entries++;
        // Return.
        return;
    }

    // If we have reached the maximum cap of entries,
    if (current_number_entries == max_number_entries) {
        // If the new entry is not larger than the smallest (i.e. the last)
        // entry.
        if (e.get_entry_value() <= entries[current_number_entries - 1].get_entry_value()) {
            // Abort.
            return;
        }

        // This means that the new entry is large enough to at least replace
        // the lowest (last) entry.
        int lowest_entry_index = current_number_entries - 1;
        int next_entry_index = lowest_entry_index - 1;
        while (next_entry_index >= 0) {
            // If the next_entry is larger than our new entry, 
            if (entries[next_entry_index].get_entry_value() > e.get_entry_value()) {
                // Place the new entry in lowest_entry_index
                entries[lowest_entry_index] = e;
                // Return.
                return;
            }

            // Else (if the next entry is smaller than or equal to our new entry),
            // Place the next_entry in the lowest_entry_index
            entries[lowest_entry_index] = entries[next_entry_index];
            // Make the lowest_entry_index equal the next_entry_index.
            lowest_entry_index = next_entry_index;
            // Update the next_entry_index.
            next_entry_index--;
        }
    
        // This means that the the entry at index 0 (the largest entry) is less
        // than **or equal** to our new entry.

        // If the entry at index 0 (the largest entry) is less than our new
        // entry, let's replace the entry at index 0 by our new entry:
        entries[0] = e;
        // And return.
        return;
    }

    // This means that we, at the very least, have space for a new entry.
    current_number_entries++;
    

    // // If we currently have less entries than the max,
    // if (current_number_entries < max_number_entries) {
    //     // Append the new entry.
    //     entries[current_number_entries] = e;
    //     // Update the entry count.
    //     current_number_entries += 1;
    //     // Finish the addition process.
    //     return;
    // }

    // // This means we have the max amount of possible entries.
    // 
    // // Initialize a "smaller entries" count.
    // int smaller_entries = 0;
    // // Initialize a "first small entry" index to -1 (because 0 is also valid
    // // index).
    // int first_small_entry = -1;

    // // For each current entry:
    // for (int i = 0; i < current_number_entries; i++) {
    //     const Entry &curr_entry = entries[i];

    //     // If that entry is less than the new entry
    //     if (curr_entry.get_entry_value() < e.get_entry_value()) {
    //         // Add to smaller entries
    //         smaller_entries++;
    //         // If first small entry index == -1, update it.
    //         if (first_small_entry = -1) first_small_entry = i;
    //     }
    // }

    // // If there are no smaller entries, return.
    // if (smaller_entries == 0) return;

    // // Figure out the index of the smaller entry to remove.
    // int index_to_remove = (first_small_entry + smaller_entries) - 1;

    // // Make a call to the remove function.
    // return;
}

void MaxEntries::print() { 
    std::cout << "MaxEntries: ";
    for (int i = 0; i < max_number_entries; i++) {
        std::cout << entries[i].get_entry_value() << " ";
    }
}

int main(void) {
    const int max = 10;
    
    // Instantiate a new `MaxEntries` object by specifying the maximum possible
    // number of entries.
    MaxEntries m_es(max);

    // Create a populating loop; populates all but the last entry in the array.
    for (int i = 1; i < (max); i++) {
        Entry e(i);
        m_es.add_entry(e);
    }

    m_es.print();

    return 0;
}
