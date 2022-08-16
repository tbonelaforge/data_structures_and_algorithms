#include <iostream>
#include <fstream>

#include "UnorderedList.h"

using namespace std;

int main(int argc, char * argv[]) {
    if (argc < 2) {
        cout << "Error: Missing input filename" << endl
             << "Usage: \n" << argv[0] << " test_cases.txt" << endl;
        return 1;
    }
    ifstream inFile;
    inFile.open(argv[1]);
    if (!inFile) {
        cout << "File " << argv[1] << " was not found." << endl;
        return 1;
    }
    string command;
    int itemValue;
    UnorderedList ul;
    ItemType item;
    while (inFile >> command) {
        if (command == "putItem") {
            inFile >> itemValue;
            item.Initialize(itemValue);
            ul.putItem(item);
            cout << "putItem: ";
            item.Print(cout);
            cout << endl;
        } else if (command == "printList") {
            cout << "printList: ";
            ul.printList();
        } else if (command == "getLength") {
            cout << "getLength: " << ul.getLength() << endl;
        } else if (command == "deleteItem") {
            inFile >> itemValue;
            item.Initialize(itemValue);
            ul.deleteItem(item);
            cout << "deleteItem: ";
            item.Print(cout);
            cout << endl;
        } else if (command == "hasNext") {
            cout << "hasNext: " << ul.hasNext() << endl;
        }
    }
}
