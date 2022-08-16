#ifndef _PRIORITY_QUEUE_HPP_
#define _PRIORITY_QUEUE_HPP_

#include "heap.hpp"

class FullQueue {};
class EmptyQueue {};

template<class Item>
class PriorityQueue {
public:
    PriorityQueue(int maxElements) : heap(Heap<Item>(maxElements)) {};
    void enqueue(Item item);
    Item dequeue();
    bool isEmpty();
    bool isFull();
private:
    Heap<Item> heap;
};


template<class Item>
void PriorityQueue<Item>::enqueue(Item item) {
    if (isFull()) {
        throw FullQueue();
    }
    heap.elements[heap.bottom] = item;
    heap.bottom += 1;
    heap.reHeapUp(heap.bottom - 1);
}

template<class Item>
Item PriorityQueue<Item>::dequeue() {
    if (isEmpty()) {
        throw EmptyQueue();
    }
    Item popped = heap.elements[0];
    heap.elements[0] = heap.elements[heap.bottom - 1];
    heap.bottom -= 1;
    heap.reHeapDown(0);
    return popped;
}


template<class Item>
bool PriorityQueue<Item>::isFull() {
    return heap.bottom >= heap.maxElements;
}

template<class Item>
bool PriorityQueue<Item>::isEmpty() {
    return heap.bottom <= 0;
}

#endif
