#include <iostream>

#include "ItemType.h"

using namespace std;

ItemType::ItemType(int x) {
    v = x;
}

RelationType ItemType::compareTo(ItemType other) {
    if (v < other.v) {
        return LESS;
    } else if (v > other.v) {
        return GREATER;
    } else {
        return EQUAL;
    }
}

void ItemType::printItem() {
    cout << v;
}
