#include <iostream>

#include "UnorderedList.h"

using namespace std;

int main() {
    cout << "About to construct a new UnorderedList..." << endl;
    UnorderedList ul;
    cout << "About to print the list..." << endl;
    ul.printList();
    cout << "The length is:  " << ul.getLength() << endl;
    cout << "About to put item on the list..." << endl;
    ItemType item1;
    item1.Initialize(1);
    ul.putItem(item1);
    cout << "About to print the list..." << endl;
    ul.printList();
    cout << "The length is: " << ul.getLength() << endl;
    cout << "About to put another item on the list..." << endl;
    ItemType item2;
    item2.Initialize(2);
    ul.putItem(item2);
    cout << "About to print the list..." << endl;
    ul.printList();
    cout << "The length is: " << ul.getLength() << endl;
    cout << "About to search for the item 2: " << endl;
    ItemType target;
    target.Initialize(1);
    bool found;
    ItemType result = ul.getItem(target, found);
    cout << "The result of searching for 1 is:" << endl;
    result.Print(cout);
    cout << " found is: " << found << endl;
    cout << "The result of searching for 3 is:" << endl;
    target.Initialize(3);
    result = ul.getItem(target, found);
    result.Print(cout);
    cout << " found is: " << found << endl;
    cout << "About to add a third item..." << endl;
    ItemType item3;
    item3.Initialize(1);
    cout << "Now the list looks like:" << endl;
    ul.printList();
    cout << "Now the length is: " << ul.getLength() << endl;
}
