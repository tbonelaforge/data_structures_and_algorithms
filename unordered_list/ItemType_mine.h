#ifndef _ITEM_TYPE_H_
#define _ITEM_TYPE_H_


enum RelationType { LESS, EQUAL, GREATER };

class ItemType {
 public:
    //ItemType(int x);
    RelationType compareTo(ItemType other);
    void printItem();
 private:
    int v;
};

#endif
