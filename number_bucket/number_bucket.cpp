#include <stdexcept>
#include <iostream>
#include "number_bucket.h"
#include "node.h"

NumberBucket::NumberBucket() {
    std::cout << "Inside the no-argument constructor, got called...\n" << std::endl;
    size = 0;
    id = 0;
}

NumberBucket::NumberBucket(int id) {
    std::cout << "Inside the id constructor, got called with id: " << id << std::endl;
    size = 0;
    this->id = id;
}

struct node * NumberBucket::getHead() {
    return head;
}

int NumberBucket::getSize() {
    return size;
}

bool NumberBucket::isEmpty() {
    if (head) {
        return false;
    } else {
        return true;
    }
}

void NumberBucket::push(int n) {
    node * thisNode = new node();
    thisNode->value = n;
    thisNode->next = head;
    head = thisNode;
    size += 1;
}


int NumberBucket::pop() {
    node * top = head;
    if (!top) {
        throw std::runtime_error("Cannot pop from an empty list!");
    }
    head = top->next;
    int v = top->value;
    delete top;
    return v;
}

NumberBucket::~NumberBucket() {
    std::cout << "The destructor for the number bucket " << id << " got called!" << std::endl;
    while (!isEmpty()) {
        pop();
    }
}
