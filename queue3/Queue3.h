#ifndef _QUEUE_3_H_
#define _QUEUE_3_H_

#include <iostream>

class EmptyQueue {};

struct Node {
    int value;
    Node * next;
};

class Queue3 {
 public:
    Queue3();
    ~Queue3();
    void enqueue(int v);
    int dequeue();
    bool isEmpty();
    void print(std::ostream& out);
 private:
    Node * tail;
};

#endif
