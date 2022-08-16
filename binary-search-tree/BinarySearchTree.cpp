
#include <iostream>

#include <cstddef>

#include <cstdio>

#include "BinarySearchTree.h"
#include "List.hpp"

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    delete_recursive(root);
}

void BinarySearchTree::delete_recursive(BinaryNode * tree) {
    if (tree == NULL) {
        return;
    }
    delete_recursive(tree->left);
    delete_recursive(tree->right);
    delete tree;
}


void BinarySearchTree::insert(int value) {
    insert_recursive(root, value);
}

void BinarySearchTree::insert_recursive(BinaryNode *& tree, int value) {
    BinaryNode * newNode = new BinaryNode();
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    if (tree == NULL) {
        tree = newNode;
        return;
    }
    if (tree->value > value) {
        insert_recursive(tree->left, value);
    } else {
        insert_recursive(tree->right, value);
    }
}

List<int> BinarySearchTree::list_values() {
    List<int> value_list;
    list_values_recursive(root, value_list);
    return value_list;
}


void BinarySearchTree::list_values_recursive(BinaryNode * tree, List<int>& output) {
    if (tree == NULL) {
        return;
    }
    list_values_recursive(tree->left, output);
    output.push(tree->value);
    list_values_recursive(tree->right, output);
}

