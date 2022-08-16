
#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <string>

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
    bool remove(int value);
    List<int> list_values();
    string toString();
    int toScore(int height);
 private:
    BinaryNode * root;
    void static delete_recursive(BinaryNode * tree);
    void static insert_recursive(BinaryNode * & tree, int value);
    void static list_values_recursive(BinaryNode * tree, List<int>& output);
    bool static remove_recursive(BinaryNode * & tree, int value);
    int static get_max_value(BinaryNode& tree);
    string static to_string_recursive(BinaryNode * tree);
    int static calculate_balance_score(BinaryNode * tree, int offset, int height);
};

#endif
