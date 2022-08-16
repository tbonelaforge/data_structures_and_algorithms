
#include <cstdio>

#include <iostream>

#include "CircularDoublyLinkedList.h"


CircularDoublyLinkedList::CircularDoublyLinkedList() {
    tail = NULL;
}

void CircularDoublyLinkedList::print(std::ostream& out) {
    out << "[";
    if (!isEmpty()) {
        Node * current = tail->next;
        bool moreToPrint = true;
        while (moreToPrint) {
            out << current->value;
            if (current != tail) {
                out << ", ";
                current = current->next;
            } else {
                moreToPrint = false;
            }
        }
    }
    out << "]";
}

bool CircularDoublyLinkedList::isEmpty() {
    return !tail;
}

void CircularDoublyLinkedList::append(int n) {
    Node * newNode = new Node();
    newNode->value = n;
    newNode->next = NULL;
    if (isEmpty()) {
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
        return;
    }
    newNode->next = tail->next;
    newNode->prev = tail;
    tail->next->prev = newNode;
    tail->next = newNode;
    tail = newNode;
}

void CircularDoublyLinkedList::insert(int n) {
    Node * newNode = new Node();
    newNode->value = n;
    newNode->next = NULL;
    if (isEmpty()) {
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
        return;
    }
    newNode->next = tail->next;
    newNode->prev = tail;
    tail->next->prev = newNode;
    tail->next = newNode;
}
