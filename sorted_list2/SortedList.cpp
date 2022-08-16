#include <cstddef>
#include <string>

#include "SortedList.h"


SortedList::SortedList() {
    head = NULL;
    length = 0;
    reset();
}


SortedList::~SortedList() {
    deleteNodes();
}

void SortedList::makeEmpty() {
    deleteNodes();
    length = 0;
    reset();
}


void SortedList::reset() {
    currentPos = NULL;
}


void SortedList::putItem(ItemType item) {
    Node * current = head;
    Node * previous = NULL;
    while (current != NULL) {
        if (current->info.ComparedTo(item) == GREATER) {
            break;
        }
        previous = current;
        current = current->next;
    }
    Node * newNode = new Node();
    newNode->info = item;
    if (previous != NULL) {
        previous->next = newNode;
    } else {
        head = newNode;
    }
    newNode->next = current;
    length += 1;
}

void SortedList::deleteNodes() {
    while (head != NULL) {
        Node * next = head->next;
        delete head;
        head = next;
    }    
}

bool SortedList::hasNext() {
    if (currentPos != NULL) {
        return currentPos->next;
    }
    return head;
}

ItemType SortedList::getNext() {
    if (!hasNext()) {
        throw std::string("No next item!");
    }
    Node * next;
    if (currentPos) {
        next = currentPos->next;
    } else {
        next = head;
    }
    currentPos = next;
    return currentPos->info;
}

int SortedList::getLength() {
    return length;
}

void SortedList::deleteItem(ItemType target) {
    Node * current = head;
    Node * previous = NULL;
    while (current != NULL) {
        if (current->info.ComparedTo(target) == EQUAL) {
            break;
        }
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    if (previous != NULL) {
        previous->next = current->next;
    } else {
        head = current->next;
    }
    delete current;
    length -= 1;
}
