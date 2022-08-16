#ifndef _INTEGER_QUEUE_H_
#define _INTEGER_QUEUE_H_

class FullQueue {};
class EmptyQueue {};

class IntegerQueue {
 public:
    IntegerQueue();
    void enqueue(int v);
    int dequeue();
    bool isFull();
    bool isEmpty();
 private:
    int elements[5];
    int f;
    int r;
};

#endif
