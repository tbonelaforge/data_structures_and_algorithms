#include <cstddef>
#include <iostream>
#include <new>

#include "UnorderedList.h"


using namespace std;

Node::Node() {
    next = NULL;
}

Node::Node(ItemType item) {
    value = item;
    next = NULL;
}

UnorderedList::UnorderedList() {
    head = NULL;
    currentPos = NULL;
    length = 0;
}

void UnorderedList::deleteNodes() {
    while (Node * current = head) {
        head = current->next;
        delete current;
    }
}

UnorderedList::~UnorderedList() {
    deleteNodes();
}

void UnorderedList::PrintList(std::ostream& out) const {
    Node * current = head;
    out << "[";
    while (current) {
        ItemType currentItem = current->value;
        currentItem.print(out);
        if (current->next) {
            out << ", ";            
        }
        current = current->next;
    }
    out << "]" << endl;
}

void UnorderedList::PutItem(ItemType item) {
    Node * itemNode = new Node(item);
    itemNode->next = head;
    head = itemNode;
    length += 1;
}

int UnorderedList::GetLength() {
    return length;
}

ItemType UnorderedList::GetItem(ItemType target, bool& found) {
    Node * current = head;
    found = false;
    while (current) {
        ItemType currentItem = current->value;
        if (currentItem.compareTo(target) == EQUAL) {
            found = true;
            return currentItem;
        }
        current = current->next;
    }
    return target;
}

void UnorderedList::DeleteItem(ItemType target) {
    Node * previous = NULL;
    Node * current = head;
    while (current) {
        ItemType currentItem = current->value;
        if (currentItem.compareTo(target) == EQUAL) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            length -= 1;
            return;
        }
        previous = current;
        current = current->next;
    }
}

bool UnorderedList::HasNext() {
    if (currentPos) {
        return currentPos->next;
    } else {
        return head;
    }
}

ItemType UnorderedList::GetNext() {
    if (!HasNext()) {
        throw "No next item";
    }
    if (currentPos) {
        currentPos = currentPos->next;
    } else {
        currentPos = head;
    }
    return currentPos->value;
}

void UnorderedList::MakeEmpty() {
    deleteNodes();
    length = 0;
    currentPos = NULL;
}

bool UnorderedList::IsFull() {
    Node * temp = NULL;
    try {
        temp = new Node();
        delete temp;
        return false;
    } catch (const bad_alloc& e) {
        delete temp;
        return true;
    }
}

void UnorderedList::reset() {
    currentPos = NULL;
}
