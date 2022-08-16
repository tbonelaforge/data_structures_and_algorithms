#include <iostream>
#include <stdexcept>

struct node {
    int value;
    node * next;
};

class NumberBucket {
 public:
    NumberBucket() {
        size = 0;
        head = nullptr;
    }

    void push(int n) {
        node * valueNode = new struct node();
        valueNode->value = n;
        valueNode->next = head;
        head = valueNode;
        size += 1;
    }

    int pop() {
        if (isEmpty()) {
            throw std::runtime_error("Cannot pop from an empty list!");
        }
        node * top = head;
        int v = top->value;
        head = top->next;
        delete top;
        size -= 1;
        return v;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return !head ? true : false;
    }

    ~NumberBucket() {
        while (!isEmpty()) {
            pop();
        }
    }

 private:
    int size;
    struct node * head;
};


