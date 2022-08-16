#ifndef _HEAP_HPP_
#define _HEAP_HPP_

#include <iostream>
using namespace std;

template<class Item>
struct Heap {
    Heap(int maxItems);
    ~Heap();
    void reHeapUp(int i);
    void reHeapDown(int i);
    void swap(int i, int j);
    Item * elements;
    int bottom;
    int maxElements;
};

template<class Item>
Heap<Item>::Heap(int maxItems) {
    maxElements = maxItems;
    elements = new Item[maxItems];
    bottom = 0; // next place to insert
}

template<class Item>
Heap<Item>::~Heap() {
    delete[] elements;
}

template<class Item>
void Heap<Item>::reHeapUp(int i) {
    if (i <= 0) {
        return;
    }
    int parent = (i - 1) / 2;
    if (elements[parent] < elements[i]) {
        swap(parent, i);
    }
    return reHeapUp(parent);
}

template<class Item>
void Heap<Item>::reHeapDown(int i) {
    cout << "Inside reHeapDown, got called with i = "  << i << endl;
    if (i >= bottom) {
        return;
    }
    int left_child = 2 * i + 1;
    if (left_child >= bottom) {
        return;
    }
    Item maxChild = elements[left_child];
    int max_child_index = left_child;
    int right_child = left_child + 1;
    if (right_child < bottom && elements[right_child] > maxChild) {
        maxChild = elements[right_child];
        max_child_index = right_child;
    }
    if (elements[i] < maxChild) {
        swap(i, max_child_index);
    }
    return reHeapDown(max_child_index);
}

template<class Item>
void Heap<Item>::swap(int i, int j) {
    Item temp = elements[i];
    elements[i] = elements[j];
    elements[j] = temp;
}

#endif
