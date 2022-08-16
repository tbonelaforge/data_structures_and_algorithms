
#include <iostream>

struct Node {
    int value;
    Node * next;
    Node * prev;
};

class CircularDoublyLinkedList {
 public:
    CircularDoublyLinkedList();
    void print(std::ostream& out);
    void append(int n);
    void insert(int n);
    bool isEmpty();
 private:
    Node * tail;
};
