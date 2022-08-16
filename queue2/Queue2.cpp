#include <cstddef>
#include <iostream>

#include "Queue2.h"

using namespace std;

Queue2::Queue2() {
    head = NULL;
    tail = NULL;
}

Queue2::~Queue2() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue2::enqueue(int v) {
    Node * newNode = new Node();
    newNode->value = v;
    newNode->next = NULL;
    if (tail != NULL) {
        tail->next = newNode;
        tail = newNode;
    } else {
        head = newNode;
        tail = newNode;
    }
}

int Queue2::dequeue() {
    if (isEmpty()) {
        throw EmptyQueue();
    }
    Node * next = head->next;
    int v = head->value;
    delete head;
    head = next;
    if (head == NULL) {
        tail = NULL;
    }
    return v;

}

bool Queue2::isEmpty() {
    return !head;
}

void Queue2::print(std::ostream& out) {
    Node * current = head;
    out << "[";
    while (current != NULL) {
        out << current->value;
        if (current->next != NULL) {
            out << ", ";
        }
        current = current->next;
    }
    out << "]";
}
