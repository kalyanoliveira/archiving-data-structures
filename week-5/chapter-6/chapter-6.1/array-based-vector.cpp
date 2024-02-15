// Here, we do a dynamic array based vector.

// We need functions:
// at
// insert
// erase
// size
// empty

#include <iostream>

class Vector {
    public:
        Vector();
        ~Vector();

        int size() const;
        bool empty() const;

        int at(const int &i) const;

        void insert(const int &i, const int &v);
        void erase(const int &i);

        // Reserves enough space in memory for the specified capacity.
        void reserve(const int &c);

    private:
        int capacity;
        int *elements;
        int number_of_elements;

};

Vector::Vector() { 
    capacity = 0;
    elements = NULL;
    number_of_elements = 0;
}

Vector::~Vector() {
    if (elements != NULL) delete [] elements;
}

int Vector::size() const {
    return number_of_elements;
}

bool Vector::empty() const {
    return number_of_elements == 0;
}

int Vector::at(const int &i) const {
    if (i < 0 || i >= number_of_elements) {
        std::cout << "At: Index out of bounds, returning -1..." << std::endl;
        return -1;
    }

    return elements[i];
}

// This function assumes that we never try to access in invalid index.
// Which is bad, but whatever.
void Vector::insert(const int &i, const int &v) {
    // If the current number of elements is greater than or equal to our
    // capacity, this means that we need to allocate space for at least one
    // more element.
    if (number_of_elements >= capacity) {
        reserve(capacity + 1);
    }

    // Now, we need to shift the elements [i, number_of_elements) up by one
    // unit.
    for (int temp = number_of_elements - 1; temp >= i; temp--) {
        elements[temp + 1] = elements[temp];
    }

    elements[i] = v;

    number_of_elements++;
}

void Vector::erase(const int &i) {
    if (empty()) return;
    // Basically, we need to shift the elements [i + 1, number_of_elements) one
    // unit down.
    for (int temp = i + 1; temp < number_of_elements; temp ++) {
        elements[temp - 1] = elements[temp];
    }
    
    number_of_elements--; 
}

void Vector::reserve(const int &c) {
    // If the current capacity is enough for the new capacity, just return.
    if (c <= capacity) return;

    // This means that we need more space.
    
    // Create a new dynamic array with more space.
    int *new_elements = new int[c]; 

    // Copy the contents of the old array into the new one.
    for (int j = 0; j < number_of_elements; j++) {
        new_elements[j] = elements[j];
    }

    // Delete the contents of the old array (if it is not NULL).
    if (elements != NULL) delete [] elements;
    
    // Make `elements` point to the new array.
    elements = new_elements;
    
    // Update our capacity to reflect the new capacity value.
    capacity = c;
}

int main(void) {
    Vector v;

    v.insert(0, 0);
    v.insert(1, 1);
    v.insert(2, 2);
    v.insert(3, 3);

    std::cout << v.at(0) << std::endl;
    std::cout << v.at(1) << std::endl;
    std::cout << v.at(2) << std::endl;
    std::cout << v.at(3) << std::endl;

    v.erase(2);
    std::cout << v.at(0) << std::endl;
    std::cout << v.at(1) << std::endl;
    std::cout << v.at(2) << std::endl;

    return 0;
}
