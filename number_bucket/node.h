#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>

struct node {
    int value;
    node * next;

    ~node() {
        std::cout << "Inside the node destructor for value: " << value << ", got calledz!" << std::endl;
    }
};

#endif
