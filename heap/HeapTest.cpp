
#include "Heap.hpp"

#include <iostream>

using namespace std;

template<class Item> void printHeap(Heap<Item>& h) {
    for (int i = 0; i < h.bottom; i++) {
        cout << h.elements[i] << endl;
    }
}

int main() {
    cout << "About to construct a new Heap with maxElements of 7..." << endl;
    Heap<int> heap(7);
    heap.elements[0] = 1;
    heap.elements[1] = 2;
    heap.elements[2] = 3;
    heap.elements[3] = 4;
    heap.elements[4] = 5;
    heap.elements[5] = 6;
    heap.elements[6] = 7;
    int original_bottom = 7;
    heap.bottom = original_bottom;
    cout << "Initially, the heap looks like:" << endl;
    printHeap(heap);
    cout << "About to reHapDown, starting at element[6]" << endl;
    int i;
    i = 6;
    heap.reHeapDown(i);
    cout << "After reHeapDown(" <<  i << ") we have:" << endl;
    printHeap(heap);
    i = 5;
    heap.reHeapDown(i);
    cout << "After reHeapDown(" <<  i << ") we have:" << endl;
    printHeap(heap);
    i = 4;
    heap.reHeapDown(i);
    cout << "After reHeapDown(" <<  i << ") we have:" << endl;
    printHeap(heap);
    i = 3;
    heap.reHeapDown(i);
    cout << "After reHeapDown(" <<  i << ") we have:" << endl;
    printHeap(heap);
    i = 2;
    heap.reHeapDown(i);
    cout << "After reHeapDown(" <<  i << ") we have:" << endl;
    printHeap(heap);
    i = 1;
    heap.reHeapDown(i);
    cout << "After reHeapDown(" <<  i << ") we have:" << endl;
    printHeap(heap);
    i = 0;
    heap.reHeapDown(i);
    cout << "After reHeapDown(" <<  i << ") we have:" << endl;
    printHeap(heap);


    cout << "Now about to sort..." << endl;
    /*
    top_element = heap.elements[0];
    heap.elements[0] = heap.elements[--heap.bottom];
    heap.reHeapDown(0);
    cout << "After the first sort step, we have: " << endl;
    printHeap(heap);
    */
    //int count = 0;
    while (heap.bottom) {
        int top_of_heap = heap.elements[0];
        cout << top_of_heap << endl;
        //heap.elements[0] = heap.elements[heap.bottom - 1];
        //heap.elements[heap.bottom - 1] = top_of_heap
        heap.swap(0, heap.bottom - 1);
        heap.bottom -= 1;
        cout << "After the swap, we have elements: " << endl;
        for (int i = 0; i < original_bottom; i++) {
            cout << heap.elements[i];
        }
        cout << endl;
        heap.reHeapDown(0);
        cout << "After the reHeapDown, we have elements: " << endl;
        for (int i = 0; i < original_bottom; i++) {
            cout << heap.elements[i];
        }
        cout << endl;
        //count += 1;
    }
    cout << "After the sorting loop, we have:" << endl;
    for (int i = 0; i < original_bottom; i++) {
        cout << heap.elements[i] << endl;
    }
    cout << "And that is alllllllll" << endl;
    
}
