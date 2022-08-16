#ifndef _UNORDERED_LIST_H_
#define _UNORDERED_LIST_H_

#include <iostream>

//#include "ItemType.h"
#include "Card.h"

struct Node {
    Node();
    Node(ItemType item);
    ItemType value;
    Node * next;
};

class UnorderedList {
 public:
    UnorderedList();
    ~UnorderedList();
    void PrintList(std::ostream& out) const;
    void PutItem(ItemType item);
    int GetLength();
    ItemType GetItem(ItemType target, bool& found);
    void DeleteItem(ItemType target);
    bool HasNext();
    ItemType GetNext();
    void MakeEmpty();
    bool IsFull();
    void reset();
 private:
    Node * head;
    Node * currentPos;
    int length;
    void deleteNodes();
};

#endif
