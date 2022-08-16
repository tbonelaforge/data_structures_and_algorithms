#ifndef _INTEGER_QUEUE_H_
#define _INTEGER_QUEUE_H_

class FullQueue {};
class EmptyQueue {};

template <class ItemType>
class Queue {
 public:
    Queue();
    void enqueue(ItemType item);
    ItemType dequeue();
    bool isFull();
    bool isEmpty();
 private:
    ItemType items[5];
    int f;
    int r;
};

template <class ItemType> Queue<ItemType>::Queue() {
    f = 0;
    r = 0;
}

template <class ItemType>
void Queue<ItemType>::enqueue(ItemType item) {
    if (isFull()) {
        throw FullQueue();
    }
    items[r] = item;
    r = (r + 1) % 5;
}

template <class ItemType>
bool Queue<ItemType>::isFull() {
    return (r + 1) % 5 == f;
}

template <class ItemType>
bool Queue<ItemType>::isEmpty() {
    return r == f;
}

template <class ItemType>
ItemType Queue<ItemType>::dequeue() {
    if (isEmpty()) {
        throw EmptyQueue();
    }
    ItemType item = items[f];
    f = (f + 1) % 5;
    return item;
}

#endif
