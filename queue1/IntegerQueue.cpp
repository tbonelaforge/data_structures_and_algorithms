#include <iostream>

#include "IntegerQueue.h"

IntegerQueue::IntegerQueue() {
    f = 0;
    r = 0;
}

void IntegerQueue::enqueue(int v) {
    if (isFull()) {
        throw FullQueue();
    }
    elements[r] = v;
    r = (r + 1) % 5;
    std::cout << "[r is " << r << " f is " << f << "]";
}

int IntegerQueue::dequeue() {
    if (isEmpty()) {
        throw EmptyQueue();
    }
    int v = elements[f];
    f = (f + 1) % 5;
    std::cout << "[r is " << r << " f is " << f << "]";
    return v;
}

bool IntegerQueue::isFull() {
    return (r + 1) % 5 == f;
}

bool IntegerQueue::isEmpty() {
    return r == f;
}
