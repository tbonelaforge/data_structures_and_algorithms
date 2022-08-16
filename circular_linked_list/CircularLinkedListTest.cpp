
#include "CircularLinkedList.hpp"

#include <string>
#include <iostream>

#include "RelationType.h"

using namespace std;


class StringItem {
public:
    StringItem() {};
    StringItem(string s) : data(s) {};
    void print(ostream& out) {
        out << data;
    };
    RelationType comparedTo(StringItem other) {
        return (data < other.data) ? LESS : (data > other.data) ? GREATER : EQUAL;
    };
private:
    string data;
};

int main() {
    cout << "About to construct a new circular linked list..." << endl;
    CircularLinkedList<StringItem> cl;
    cout << "The new list looks like:" << endl;
    cl.print(cout);
    cout << endl << "And that is all!" << endl;
    cout << "About to put a new string item in the list..." << endl;
    StringItem si("Terry");
    cl.putItem(si);
    cout << "After puttin the item, the list looks like:" << endl;
    cl.print(cout);
    cout << endl;
    cout << "About to put a new item:" << endl;
    cl.putItem(StringItem("Tam"));
    cout << "After putting the new item, the list looks like:" << endl;
    cl.print(cout);
    cout << endl;
    cout << "About to put another new item, which should go in the middle...\n";
    cl.putItem(StringItem("Test"));
    cout << "After putting the additional new item, we have the list looking like:\n";
    cl.print(cout);
    cout << "About to put a new item at the end...\n";
    cl.putItem(StringItem("Zebra"));
    cout << "After putting the end item, we now have the list looking like:" << endl;
    cl.print(cout);
    cout << "About to put a new item at the beginning...\n";
    cl.putItem(StringItem("Aaron"));
    cout << "Now looks like:\n";
    cl.print(cout);
    cout << endl;
    

    cout << "TEST SECTION ON FIND ITEM" << endl;
    // TEST SECTION ON FIND ITEM
    bool found;
    cout << "About to search for item Test..." << endl;

    StringItem foundItem = cl.getItem(StringItem("Test"), found);
    cout << "the result of findItem(Test) is:" << found;
    cout << "the found item is: ";
    foundItem.print(cout);



    cout << "Now I'm about to delete Tam from the list..." << endl;
    cl.deleteItem(StringItem("Tam"));
    cout << "After deleting Tam, we have:" << endl;
    cl.print(cout);
    cout << "About to delete a non-existent item from the list..." << endl;
    cl.deleteItem(StringItem("Poopy"));
    cout << "After deleting the nonexistent element, we now have full list:" << endl;
    cl.print(cout);
    cout << "About to delete Terry..." << endl;
    cl.deleteItem(StringItem("Terry"));
    cout << "Now looks like:" << endl;
    cl.print(cout);
    cout << "ABout to delete Aaron and Zebra:" << endl;
    cl.deleteItem(StringItem("Zebra"));
    cl.deleteItem(StringItem("Aaron"));
    cout << "Now looks like:" << endl;
    cl.print(cout);
    cout << "About to delete the last item:" << endl;
    cl.deleteItem(StringItem("Test"));
    cout << "Now we have:" << endl;
    cl.print(cout);
    cout << "Try to delete from empty!" << endl;
    cl.deleteItem(StringItem("Poopface"));
    cout << "Now looks like: " << endl;
    cl.print(cout);
}
