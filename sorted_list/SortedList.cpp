#include <iostream>
#include <string>

#include "SortedList.h"

SortedList::SortedList(int maxLength) : maxLength(maxLength) {
    items = new ItemType[maxLength];
    makeEmpty();
}

SortedList::~SortedList() {
    std::cout << "Inside the Destructor, got called....\n" << std::endl;
    delete[] items;
}

void SortedList::putItem(ItemType item) {
    if (isFull()) {
        throw std::string("List is Full");
    }
    bool found;
    int insertPos = findPos(item, found) + 1;
    for (int i = length; i > insertPos; i--) {
        items[i] = items[i - 1];
    }
    items[insertPos] = item;
    length += 1;
}

int SortedList::findPos(ItemType target, bool& found) {
    int i = 0;
    int j = length - 1;
    int m;
    RelationType comparison;
    while (i <= j) {
        m = (i + j) / 2;
        comparison = items[m].ComparedTo(target);
        if (comparison == EQUAL) {
            found = true;
            return m;
        }
        if (comparison == LESS) {
            i = m + 1;
        } else {
            j = m - 1;
        }
    }
    found = false;
    return j;
}

bool SortedList::isFull() {
    return length >= maxLength;
}

int SortedList::getLength() {
    return length;
}

int SortedList::getMaxLength() {
    return maxLength;
}

bool SortedList::hasNext() {
    return currentPos + 1 < length;
}

ItemType SortedList::getNext() {
    if (!hasNext()) {
        throw std::string("No next item");
    }
    currentPos += 1;
    return items[currentPos];
}

void SortedList::reset() {
    currentPos = -1;
}

void SortedList::deleteItem(ItemType target) {
    bool found;
    int targetPos = findPos(target, found);
    std::cout << "Inside deleteItem, got targetPos: " << targetPos << std::endl;
    if (!found) {
        return;
    }
    for (int i = targetPos + 1; i < length; i++) {
        items[i - 1] = items[i];
    }
    length -= 1;
}

void SortedList::makeEmpty() {
    length = 0;
    currentPos = -1;
}

ItemType SortedList::getItem(ItemType target, bool& found) {
    int pos = findPos(target, found);
    if (found) {
        return items[pos];
    } else {
        return target;
    }
}
