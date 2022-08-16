
#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include "List.hpp"


struct BinaryNode {
    int value;
    BinaryNode * left;
    BinaryNode * right;
};


class BinarySearchTree {
 public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(int value);
    List<int> list_values();
 private:
    BinaryNode * root;
    void static delete_recursive(BinaryNode * tree);
    void static insert_recursive(BinaryNode * & tree, int value);
    void static list_values_recursive(BinaryNode * tree, List<int>& output);
};

#endif
