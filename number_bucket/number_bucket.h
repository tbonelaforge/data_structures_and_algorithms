#ifndef _NUMBER_BUCKET_H_
#define _NUMBER_BUCKET_H_

#include "node.h"

class NumberBucket {
 public:
    NumberBucket();

    NumberBucket(int id);

    ~NumberBucket();

    void push(int n);

    int pop();

    bool isEmpty();

    int getSize();

    struct node * getHead();

 private:
    struct node * head;
    int size;
    int id;

};

#endif
