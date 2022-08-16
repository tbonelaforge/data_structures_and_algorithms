#ifndef _SORTED_LIST_H_
#define _SORTED_LIST_H_

#include "ItemType.h"

class SortedList {
 public:
    SortedList(int maxLength);
    ~SortedList();
    void putItem(ItemType item);
    ItemType getItem(ItemType target, bool& found);
    bool hasNext();
    ItemType getNext();
    void makeEmpty();
    void reset();
    void deleteItem(ItemType target);
    bool isFull();
    int getLength();
    int getMaxLength();
 private:
    SortedList(SortedList& other); // Forbid pass by value.
    int findPos(ItemType target, bool& found);
    int maxLength;
    ItemType * items;
    int length;
    int currentPos;
};

#endif
