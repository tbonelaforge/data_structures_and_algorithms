
#include <iostream>

#include "BinarySearchTree.h"
#include "List.hpp"

int main() {
    cout << "About to construct a new binary search tree..." << endl;
    BinarySearchTree bst;
    cout << "About to insert the value 1 into the tree..." << endl;
    bst.insert(1);
    cout << "Made it past the insert..." << endl;
    cout << "About to list the values..." << endl;
    //List<int> value_list;
    cout << bst.list_values() << endl;

    cout << "About to insert the values 0, 2 into the tree..." << endl;
    bst.insert(0);
    bst.insert(2);
    cout << "Made it past the insert..." << endl;
    cout << "About to list the values..." << endl;
    //List<int> value_list2;
    cout << bst.list_values() << endl;
    cout << "About to try and remove the value 0..." << endl;
    bool result = bst.remove(0);
    cout << "The result of removing 0 is:" << (  result ? "true" : "false" ) << endl;
    cout << "Now the tree contains values:" << endl;
    cout << bst.list_values() << endl;
    return 0;
}
