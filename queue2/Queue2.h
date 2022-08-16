#ifndef _QUEUE_2_H_
#define _QUEUE_2_H_

#include <iostream>

struct Node {
    int value;
    Node * next;
};

class EmptyQueue {};

class Queue2 {
 public:
    Queue2();
    ~Queue2();
    void enqueue(int v);
    int dequeue();
    bool isEmpty();
    void print(std::ostream& out);
 private:
    Node * head;
    Node * tail;
};

#endif
