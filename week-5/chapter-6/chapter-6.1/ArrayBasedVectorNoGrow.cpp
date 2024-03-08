#include "ArrayBasedVectorNoGrow.hpp"
#include <iostream>
#include "OutOfBounds.hpp"

Vector::Vector(const int &c) {
    number_of_elements = 0;    
    capacity = c;
    elements = new int[c];
}

Vector::~Vector() {
    delete [] elements;
}

int Vector::size() const {
    return number_of_elements;    
}

bool Vector::empty() const {
    return number_of_elements == 0;
}

int Vector::at(int index) const {
    if (index < 0 || index > number_of_elements - 1) throw OutOfBounds();
    return elements[index];
}

void Vector::insert(int index, int element) {
    // If we attempt to insert an element at
    // - a negative index
    // OR
    // - an index greater than the "index of the next available spot in the
    //   array,"
    // then we must throw.
    //
    // The "index of the next available spot in the array" equals
    // `number_of_elements`.
    if (index < 0 || index > number_of_elements) throw OutOfBounds();

    // If inserting a new element will exceed capacity, throw out of bounds.
    if (number_of_elements + 1 > capacity) throw OutOfBounds();

    // Initialize a buffer to the index of the last element in the vector.
    int j = number_of_elements - 1;

    // While the buffer has not reached `index`,
    while (j > index) {
        // Dereference the result of the sum of "the product of our buffer with
        // the byte-width of an unsigned integer" and the address of the first
        // element of the `elements` array, and assign that result to another
        // buffer.
        // lol.
        int to_move = elements[j];

        // Bind the value to the right of `j` to `to_move`.
        elements[j + 1] = to_move;

        // By decreasing j, we are essentially saying: "now try to keep moving
        // values rightwards"
        j--;
    }

    // We now need to move the value at `index` to the right too.
    // Our while loop does not do that for us because of the `j != index` loop
    // condition.
    // Also, because our loop condition is `j != index`, we know that the only
    // way that this loop cannot run is if `j` equals `index. That is, by the
    // end of the while loop, `j` will equal `index`.
    elements[index + 1] = elements[index];

    // We can insert our value.
    elements[index] = element;

    // Before we return, we *need* to remember to increase our element count.
    number_of_elements++;

    return;
}

void Vector::erase(int index) {
    // If we try to erase a negative index, or an index higher than the index
    // of the last element, throw an out of bounds exception.
    if (index < 0 || index > number_of_elements - 1) throw OutOfBounds();

    // Shift elements to the right the index one position leftwards. We have to
    // start at the index, though, else we'll be just overwriting all the
    // elements of the array up until the index with the last element of the
    // array.
    int j = index;
    // We shouldn't try to change the value of the very last element, hence 
    // `j < number_of_elements - 1`.
    while (j < number_of_elements - 1) {
        elements[j] = elements[j + 1];
        j++;
    }

    // The very last element should just get a zero.
    elements[number_of_elements - 0] = 0;

    number_of_elements--;
    
    return;
}

void Vector::set(int index, int element) {
    // If we try to set a negative index, or an index higher than the index
    // of the last element, throw an out of bounds exception.
    if (index < 0 || index > number_of_elements - 1) throw OutOfBounds();

    // Then we can simply set the new element...
    elements[index] = element;

    return;
}
