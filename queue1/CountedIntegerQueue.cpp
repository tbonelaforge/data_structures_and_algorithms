#include "CountedIntegerQueue.h"

CountedIntegerQueue::CountedIntegerQueue() : IntegerQueue() {
    length = 0;
}

void CountedIntegerQueue::enqueue(int v) {
    try {
        IntegerQueue::enqueue(v);
        length += 1;
    } catch (FullQueue) {
        throw FullQueue();
    }
}

int CountedIntegerQueue::dequeue() {
    try {
        int v = IntegerQueue::dequeue();
        length -= 1;
        return v;
    } catch (EmptyQueue) {
        throw EmptyQueue();
    }
}

int CountedIntegerQueue::getLength() {
    return length;
}
