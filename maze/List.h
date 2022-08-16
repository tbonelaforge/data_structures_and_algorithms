#ifndef _LIST_H_
#define _LIST_H_

#include <cstddef>
#include <iostream>

using namespace std;

template<class Item>
struct Node {
    Item info;
    Node * next;
};


#endif
