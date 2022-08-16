
#include <iostream>
#include <fstream>
#include <string>

#include "BinarySearchTree.h"
#include "List.hpp"

using namespace std;

void fileError(string filename) {
    cout << "File " << filename << " could not be opened." << endl;
    exit(1);
}

void print_values(List<int> value_list) {
    while (!value_list.isEmpty()) {
        int value = value_list.dequeue();
        cout << value << endl;
    }
}

int main() {
    string filename;
    ifstream infile;
    int value;
    cout << "Enter input filename to test: " << endl;
    cin >> filename;
    infile.open(filename);
    if (!infile) fileError(filename);
    cout << "Reading integers from file..." << endl;
    BinarySearchTree bst;
    while ((infile >> value)) {
        bst.insert(value);
    }
    cout << "The sorted integers are:" << endl;
    List<int> value_list = bst.list_values();
    print_values(value_list);
}
