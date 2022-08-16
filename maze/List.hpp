#ifndef _LIST_H_
#define _LIST_H_

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

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
    //List(List<Item> other);
    List& operator=(List<Item> src);
    //List& operator=(List<Item>& src);
    ~List();
    void push(Item item);
    Item dequeue();
    Item pop();
    bool isEmpty() const;
    void print(ostream& out);
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
    while (!isEmpty()) {
        pop();
    }
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
void List<Item>::print(ostream& out) {
    out << "[";
    if (!isEmpty()) {
        Node<Item> * current = tail;
        do {
            current = current->next;
            Item item = current->info;
            item.print(out);
            if (current != tail) {
                out << ", ";
            }
        } while (current != tail);
    }
    out << "]";
}

template<class Item>
bool List<Item>::isEmpty() const {
    return !tail;
}

template<class Item>
Item List<Item>::pop() {
    if (isEmpty()) {
        throw EmptyList();
    }
    Node<Item> * poppedNode = tail;
    Item poppedItem = poppedNode->info;
    if (tail->next == tail) {
        tail = NULL;
    } else {
        tail->next->prev = tail->prev;
        tail->prev->next = tail->next;
        tail = tail->prev;
    }
    delete poppedNode;
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
        tail->next = tail->next->next;
        tail->next->next->prev = tail;
    }
    delete poppedNode;
    return poppedItem;
}

template <class Item>
Node<Item>* List<Item>::getTail() const {
    return tail;
}

#endif
