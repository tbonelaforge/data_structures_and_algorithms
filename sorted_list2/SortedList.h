#ifndef _SORTED_LIST_H_
#define _SORTED_LIST_H_

#include <cstddef>

#include "ItemType.h"

struct Node {
Node() : next(NULL) {};
    ItemType info;
    struct Node * next;
};

class SortedList {
 public:
    SortedList();
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
 private:
    SortedList(SortedList& other); // Forbid pass by value.
    int length;
    Node * head;
    Node * currentPos;
    void deleteNodes();
};

#endif
