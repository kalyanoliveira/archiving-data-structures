// Queues are FIFO: first in, first out.
// Elements enter the rear, and leave through the front.

// In array-based queues, we avoid having to shift elemenst around in the array
// by having indices that point to the front and rear of the queue.

// Here, you will notice that we are using a dynamic array *in a circular
// manner* by means of the modulo operator.

#include <iostream>

class Queue {
    public:
        Queue();
        
        // Since we are using a dynamic array, we have to have a destructor.
        ~Queue();

        int size() const;

        bool is_empty() const;

        void enqueue(const int &v);
        void dequeue();

        int peek_front() const;

    private:
        // Here, we'll have our array, our indices, and an element count.
        int *elements;
        int front_index;
        int rear_index;
        int number_of_elements;
}

int main(void) {
    return 0;
}
