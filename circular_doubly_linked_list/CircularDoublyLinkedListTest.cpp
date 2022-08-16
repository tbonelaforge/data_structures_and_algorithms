
#include <iostream>

#include "CircularDoublyLinkedList.h"

using namespace std;

int main() {
    cout << "Constructing a new object..." << endl;
    CircularDoublyLinkedList cl;
    cout << "Looks like:" << endl;
    cl.print(cout);
    cout << endl << "And that is all!" << endl;
    cout << "About to append to the end of the list..." << endl;
    cl.append(1);
    cout << "Now it looks like:" << endl;
    cl.print(cout);
    cout << "About to append to the end of the list..." << endl;
    cl.append(2);
    cout << "Now it looks like:" << endl;
    cl.print(cout);
    cout << endl;
    cout << "About to insert at the beginning..." << endl;
    cl.insert(0);
    cout << "Now it looks like:" << endl;
    cl.print(cout);
    cout << endl;


    cout << "Constructing a new object..." << endl;
    CircularDoublyLinkedList cl2;
    cout << "Looks like:" << endl;
    cl2.print(cout);
    cout << endl << "And that is all!" << endl;
    cout << "About to insert to the beginning of the list..." << endl;
    cl2.insert(1);
    cout << "Now it looks like:" << endl;
    cl2.print(cout);
    cout << "About to insert to the beginning of the list..." << endl;
    cl2.insert(2);
    cout << "Now it looks like:" << endl;
    cl2.print(cout);
    cout << endl;
    cout << "About to append at the end..." << endl;
    cl2.append(0);
    cout << "Now it looks like:" << endl;
    cl2.print(cout);
    cout << endl;
}
