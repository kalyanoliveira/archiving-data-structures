#include "vector.hpp"
#include "empty.hpp"
#include "index-exception.hpp"
#include <iostream>

Vector::Vector() {
    capacity = 0;
    a = nullptr;
    n = 0;
}

Vector::Vector(const int c) {
    capacity = c;
    a = new int[c];
    n = 0;
}

Vector::~Vector() {
    delete [] a;
}

bool Vector::empty() const {
    return n == 0;
}

int Vector::size() const {
    return n;
}

int Vector::at(const int index) const {
    // Check for an invalid index, throw IndexException if needed.
    if (index < 0 || index > n - 1) 
        throw IndexException("Tried accessing invalid index of Vector in at()");

    return a[index];
}

void Vector::set(const int index, const int element) {
    // Check for an invalid index, throw IndexException if needed.
    if (index < 0 || index > n - 1) 
        throw IndexException("Tried setting an invalid index of Vector, in set()");

    a[index] = element;

    return;
}

void Vector::insert(const int index, const int element) {
    // Check for an invalid index, throw IndexException if needed.
    if (index < 0 || index > n) 
        throw IndexException("Tried inserting at an invalid index of Vector, in insert()");

    // Check for overflowing capacity, resize if needed.
    if (n + 1 > capacity) {
        // If the current capacity is zero, set the new capacity to 1.
        if (capacity == 0) resize(1);
        // Else, double the current capacity.
        else resize(capacity * 2);
    }

    // Shift all elements from [index, n - 1] one unit to the right.
    int j = n - 1;
    while (j >= index) {
        a[j + 1] = a[j];
    }

    // Actually do the insertion.
    a[j + 1] = element;
    
    // Update the element count.
    n++;

    return;
}

void Vector::erase(const int index) {
    // Check for an invalid index.
    if (index < 0 || index > n - 1) 
        throw IndexException("Tried erasing an invalid index of Vector, in erase()");

    // Move every element from the left of the index one unit leftwards,
    // starting from the index and ending at the second to last element.
    // "ending at the second to last element" means excluding the last element, hence j < n - 1
    for (int j = index; j < n - 1; j++) {
        a[j] = a[j + 1];
    }

    // Decrease the element count.
    n--;

    return; 
}

void Vector::resize(const int c) {
    // Check if the current capacity is already enough.
    if (capacity == c) return;

    int *new_a = new int[c];

    for (int i = 0; i < n; i++) {
        new_a[i] = a[i];
    }

    capacity = c;

    a = new_a;

    return;
}

void Vector::print() const {
    for (int i = 0; i < n; i++) std::cout << a[i] << " ";
    std::cout << std::endl;
}
