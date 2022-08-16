
#include <iostream>

#include <cstddef>

#include <cstdio>

#include <cmath>

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

bool BinarySearchTree::remove(int value) {
    return remove_recursive(root, value);
}

bool BinarySearchTree::remove_recursive(BinaryNode * & tree, int value) {
    if (tree == NULL) {
        return false;
    }
    if (tree->value > value) {
        return remove_recursive(tree->left, value);
    } else if (tree->value < value) {
        return remove_recursive(tree->right, value);
    }

    // tree->value == value
    if (tree->left != NULL && tree->right != NULL) {
        int predecessor_value = get_max_value(*(tree->left));
        tree->value = predecessor_value;
        return remove_recursive(tree->left, predecessor_value);
    }
    BinaryNode * p = tree;
    if (tree->right != NULL) {
        tree = tree->right;
    } else {
        tree = tree->left;
    }
    delete p;
    return true;
}

int BinarySearchTree::get_max_value(BinaryNode& tree) {
    BinaryNode * current = &tree;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->value;
}

string BinarySearchTree::toString() {
    return to_string_recursive(root);
}

string BinarySearchTree::to_string_recursive(BinaryNode* tree) {
    if (tree == NULL) {
        return string("");
    }
    string leftString = string("(") + to_string_recursive(tree->left) + string(")");
    string rightString = string("(") + to_string_recursive(tree->right) + string(")");
    return leftString + rightString + to_string(tree->value);
}

int BinarySearchTree::toScore(int height) {
    return calculate_balance_score(root, 0, height);
}

int BinarySearchTree::calculate_balance_score(BinaryNode * tree, int offset, int height) {
    if (tree == NULL) {
        return 0;
    }
    cout << "Inside calculate_balance_score, got called with offset: " << offset << " and height " << height << endl;
    int width = std::exp2(height - 1);
    cout << "Got width of: " << width << endl;
    int left_score = calculate_balance_score(tree->left, offset - width, height - 1);
    cout << "Got left_score: " << left_score << endl;
    int right_score = calculate_balance_score(tree->right, offset + width, height - 1);
    cout << "Got right_score: " << right_score << endl;
    return left_score + offset + right_score;
}
