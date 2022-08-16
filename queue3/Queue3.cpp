

#include "Queue3.h"

Queue3::Queue3() {
    tail = NULL;
}

Queue3::~Queue3() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue3::enqueue(int v) {
    Node * newNode = new Node();
    newNode->value = v;
    newNode->next = NULL;
    if (tail != NULL) {
        Node * head = tail->next;
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    } else {
        newNode->next = newNode;
        tail = newNode;
    }
}

int Queue3::dequeue() {
    if (isEmpty()) {
        throw EmptyQueue();
    }
    Node * head = tail->next;
    int v = head->value;
    Node * next = head->next;
    if (head != next) {
        tail->next = next;
    } else {
        tail = NULL;
    }
    delete head;
    return v;
}

bool Queue3::isEmpty() {
    return !tail;
}

void Queue3::print(std::ostream& out) {
    out << "[";
    if (!isEmpty()) {
        Node * head = tail->next;
        Node * current = head;
        while (current != NULL) {
            out << current->value;
            if (current->next != head) {
                out << ", ";
                current = current->next;
            } else {
                current = NULL;
            }
        }
    }
    out << "]";
}
