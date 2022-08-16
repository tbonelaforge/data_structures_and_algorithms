#ifndef _CIRCULAR_LINKED_LIST_H_
#define _CIRCULAR_LINKED_LIST_H_

#include <cstddef>
#include <iostream>

#include <cstdio>

#include "RelationType.h"

using namespace std;

template<class ItemType>
struct Node {
    ~Node() {
        cout << "Inside the destructor for Node, got called..\n";
    };
    ItemType value;
    Node * next;
};

template<class ItemType>
class CircularLinkedList {
public:
    CircularLinkedList();
    ~CircularLinkedList();
    void putItem(ItemType item);
    ItemType getItem(ItemType item, bool& found);
    void deleteItem(ItemType item);
    bool isEmpty();
    void print(ostream& out);
private:
    Node<ItemType> * tail;
    void locateItem(ItemType item, bool& found, Node<ItemType>*& previous, Node<ItemType>*& current);
};

template<class ItemType> CircularLinkedList<ItemType>::CircularLinkedList() {
    tail = NULL;
}

template<class ItemType> CircularLinkedList<ItemType>::~CircularLinkedList() {
    if (isEmpty()) {
        return;
    }
    Node<ItemType>* p = tail;
    bool moreToDelete = true;
    while (moreToDelete) {
        Node<ItemType>* next = p->next;
        delete p;
        p = next;
        if (p == tail) {
            moreToDelete = false;
        }
    }
}

template<class ItemType>
void CircularLinkedList<ItemType>::putItem(ItemType item) {
    Node<ItemType> * previous;
    Node<ItemType> * current;
    bool found;
    Node<ItemType> * newNode = new Node<ItemType>();
    printf("The new node is: %p\n", newNode);
    cout << "For ";
    item.print(cout);
    newNode->value = item;
    newNode->next = NULL;
    if (isEmpty()) {
        newNode->next = newNode;
        tail = newNode;
        return;
    }
    locateItem(item, found, previous, current);
    newNode->next = current;
    previous->next = newNode;
    if (previous == tail) {
        if (!found) {
            tail = newNode;
        }
    }
}

template<class ItemType>
void CircularLinkedList<ItemType>::locateItem(
                                            ItemType item,
                                            bool& found,
                                            Node<ItemType>*& previous,
                                            Node<ItemType>*& current
                                            ) {
    found = false;
    previous = NULL;
    current = NULL;
    if (isEmpty()) return;
    previous = tail;
    current = tail->next;
    bool moreToSearch = true;
    while (moreToSearch) {
        RelationType comp = current->value.comparedTo(item);
            if (comp == GREATER || comp == EQUAL) {
            found = true;
            return;
        }
        if (current == tail) {
            moreToSearch = false;
        }
        previous = current;
        current = current->next;
    }
}

template<class ItemType>
void CircularLinkedList<ItemType>::print(ostream& out) {
    out << "[";
    if (!isEmpty()) {
        Node<ItemType> * current = tail->next;
        bool moreToPrint = true;
        int count = 0;
        while (moreToPrint && count < 10) {
            ItemType item = current->value;
            item.print(out);
            count += 1;
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


template<class ItemType>
bool CircularLinkedList<ItemType>::isEmpty() {
    return !tail;
}

template<class ItemType>
void CircularLinkedList<ItemType>::deleteItem(ItemType target) {
    bool found;
    Node<ItemType>* current;
    Node<ItemType>* previous;
    locateItem(target, found, previous, current);
    if (!found) {
        return;
    }
    if (current->value.comparedTo(target) != EQUAL) {
        return;
    }
    cout << "Inside delete, after the find operation, realized we found the item, and we have current:\n";
    printf("%p\n", current);
    current->value.print(cout);
    cout << endl << "And previous: \n";
    previous->value.print(cout);
    if (current == previous) {
        tail = NULL;
    } else {
        previous->next = current->next;
        if (current == tail) {
            tail = previous;
        }
    }
    delete current;
}

template<class ItemType>
ItemType CircularLinkedList<ItemType>::getItem(ItemType target, bool& found) {
    bool located;
    Node<ItemType>* current;
    Node<ItemType>* previous;
    locateItem(target, located, previous, current);
    cout << "Inside getItem, the result of locateItem is:" << endl;
    cout << "located is: " << located << endl;
    cout << "The value at current is:" << endl;
    current->value.print(cout);
    cout << endl;
    cout << "The value at previous is:" << endl;
    previous->value.print(cout);
    cout << endl;
    if (!located || (current->value.comparedTo(target) != EQUAL)) {
        found = false;
        return target;
    }
    found = true;
    Node<ItemType> * foundItem = current;
    return (*foundItem).value;
}

#endif
