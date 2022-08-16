#ifndef _LIST_H_
#define _LIST_H_

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

template<class Item>
class List;

template<class Item>
ostream& operator<<(ostream& out, const List<Item>& list);


template<class Item>
struct Node {
    Item info;
    Node * next;
    Node * prev;
};

class EmptyList {};



template<class Item>
class List {
public:
    List();
    List(const List<Item>& other);
    List& operator=(List<Item> src);
    ~List();
    void push(Item item);
    Item dequeue();
    Item pop();
    bool isEmpty() const;
    Node<Item> * getTail() const;
private:
    Node<Item> * tail;
};

template<class Item>
List<Item>::List() {
    tail = NULL;
}

template<class Item>
List<Item>::List(const List<Item>& other) {
    tail = NULL;
    if (other.isEmpty()) {
        return;
    }
    Node<Item> * current = other.getTail();
    do {
        current = current->next;
        Item item(current->info);
        push(item);
    } while (current != other.getTail());
}


template<class Item>
List<Item>& List<Item>::operator=(List<Item> src) {
    std::swap(tail, src.tail);
    return *this;
}


template<class Item>
List<Item>::~List() {
    cout << "Inside the destructor for List, got called..." << endl;
    while (!isEmpty()) {
        cout << "Inside the destructor for List, about to pop..." << endl;
        pop();
    }
    cout << "Finished the destructor for list..." << endl;
}

template<class Item>
void List<Item>::push(Item item) {
    Node<Item> * newNode = new Node<Item>();
    newNode->info = item;
    if (isEmpty()) {
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = tail->next;
        newNode->prev = tail;
        tail->next->prev = newNode;
        tail->next = newNode;
    }
    tail = newNode;
}


template<class Item>
ostream& operator<<(ostream& out, const List<Item>& list) {
    out << "[";
    if (!list.isEmpty()) {
        Node<Item> * current = list.getTail();
        do {
            current = current->next;
            Item item = current->info;
            out << item;
            if (current != list.getTail()) {
                out << ", ";
            }
        } while (current != list.getTail());
    }
    return out << "]";
}


template<class Item>
bool List<Item>::isEmpty() const {
    return !tail;
}

template<class Item>
Item List<Item>::pop() {
    cout << "Inside List.pop, got called, and the current list looks like:" << endl;
    cout << *this << endl;
    if (isEmpty()) {
        throw EmptyList();
    }
    Node<Item> * poppedNode = tail;
    Item poppedItem = poppedNode->info;
    cout << "Inside List.pop, got poppedItem:" << poppedItem << endl;
    if (tail->next == tail) {
        tail = NULL;
    } else {
        tail->next->prev = tail->prev;
        tail->prev->next = tail->next;
        tail = tail->prev;
    }
    cout << "Inside List.pop, about to delete poppedNode..." << endl;
    delete poppedNode;
    cout << "Inside List.pop, about to return the poppedItem..." << endl;
    return poppedItem;
}

template<class Item>
Item List<Item>::dequeue() {
    if (isEmpty()) {
        throw EmptyList();
    }
    Node<Item> * poppedNode = tail->next;
    Item poppedItem = poppedNode->info;
    if (tail->next == tail) {
        tail = NULL;
    } else {
        Node<Item> * newHead = poppedNode->next;
        newHead->prev = tail;
        tail->next = newHead;

    }
    delete poppedNode;
    return poppedItem;
}

template <class Item>
Node<Item>* List<Item>::getTail() const {
    return tail;
}

#endif
