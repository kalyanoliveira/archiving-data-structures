#include <iostream>
#include "OutOfBounds.hpp"

class Vector {
    public:
        Vector(const int &c);
        ~Vector();

        int size() const;
        int max_size() const;
        bool empty() const;

        int at(const int &i) const;
        
        void insert(const int &i, const int &e);
        void set(const int &i, const int &e);
        void erase(const int &i);

        void resize(int const &new_c);

    private:
        int capacity;
        int number_of_elements;
        int *elements;
};

Vector::Vector(const int &c) {
    capacity = c;
    number_of_elements = 0;
    elements = new int[c];
}

Vector::~Vector() {
    delete [] elements;
}

int Vector::size() const {
    return number_of_elements;
}

int Vector::max_size() const {
    return capacity;
}

bool Vector::empty() const {
    return number_of_elements == 0;
}

int Vector::at(const int &i) const {
    if (i < 0 || i > number_of_elements - 1) throw OutOfBounds();
    return elements[i];
}

void Vector::insert(const int &i, const int &e) {
    // Check if the passed index is out of bounds.
    if (i < 0 || i > number_of_elements) throw OutOfBounds();

    // Check if we have the space to actually insert a new element.
    // If not, we'll have to resize the Vector.
    if (number_of_elements == capacity) {
        // If the current capacity is 0, make the new capacity 1;
        if (capacity == 0) resize(1);
        // Else double capacity.
        else resize(capacity * 2);
    }

    int j = number_of_elements - 1;

    while (j >= i) {
        elements[j + 1] = elements[j];
        j--;
    }

    elements[i] = e;
    
    number_of_elements++;

    return;
}

void Vector::set(const int &i, const int &e) {
    // Check if the passed index is out of bounds.
    if (i < 0 || i > number_of_elements - 1) throw OutOfBounds();

    elements[i] = e;

    return;
}
void Vector::erase(const int &i)  {
    // Check if the passed index is out of bounds.
    if (i < 0 || i > number_of_elements - 1) throw OutOfBounds();

    // Starting from the passed index, move the element to the right of the
    // current index to the current index.
    
    int j = i;

    // Note that j only ever reaches `number_of_elements - 2` i.e. the second
    // to last element.
    while (j < number_of_elements - 1) {
        elements[j] = elements[j + 1];
        j++;
    }

    number_of_elements--;

    return;
}

// Resizes the vector to be able to hold at least `new_c`.
void Vector::resize(int const &new_c) {
    // If the current capacity is equal or larger than `new_c`, do nothing.
    if (capacity >= new_c) return;

    // This means that our current capacity is less than `new_c`.
    // Create a new int array with size `new_c`.
    int *new_elements = new int[new_c];

    // Copy `elements` into `new_elements`.
    for (int i = 0; i < size(); i++) {
        new_elements[i] = elements[i];
    }

    // Make `elements` point to the new array.
    elements = new_elements;

    // Update the capacity value that our vector currently holds.
    capacity = new_c;

    return;
}

int main(void) {
    Vector v(0);

    v.insert(0, 1);

    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;

    v.insert(0, 1);
    v.insert(0, 1);
    v.insert(0, 1);

    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << v.max_size() << std::endl;

    v.insert(0, 1);

    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << v.max_size() << std::endl;
}
