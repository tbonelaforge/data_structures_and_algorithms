#ifndef _COUNTED_INTEGER_QUEUE_H_
#define _COUNTED_INTEGER_QUEUE_H_

#include "IntegerQueue.h"

class CountedIntegerQueue : public IntegerQueue {
 public:
    CountedIntegerQueue();
    void enqueue(int v);
    int dequeue();
    int getLength();
 private:
    int length;
};

#endif
