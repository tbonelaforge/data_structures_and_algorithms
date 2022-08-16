
#include <iostream>

#include <cstdlib>
#include <ctime>

#include "SortedList.h"

using namespace std;


void printSortedList(SortedList& sl) {
    sl.reset();
    cout << "[";
    while (sl.hasNext()) {
        ItemType item = sl.getNext();
        item.Print(cout);
        if (sl.hasNext()) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    cout << "About to construct a new SortedList..." << endl;
    SortedList sl;
    cout << "After constructing the new SortedList, we have length: " << sl.getLength() << " and hasNext(): " << sl.hasNext() << endl;
    cout << "About to putItem 5..." << endl;
    ItemType item5;
    item5.Initialize(5);
    sl.putItem(item5);
    cout << "The list looks like:" << endl;
    printSortedList(sl);
    cout << "About to insert a 3" << endl;
    ItemType item3;
    item3.Initialize(3);
    sl.putItem(item3);
    cout << "The list looks like:" << endl;
    printSortedList(sl);
    cout << "About to insert 5 random values..." << endl;
    time_t current_time = time(0);
    cout << "The current time for the srand seed is:" << current_time << endl;
    srand(current_time);
    for (int i = 0; i < 5; i++) {
        int x = rand() % 10 - 5;
        cout << "About to insert: " << x << endl;
        ItemType xItem;
        xItem.Initialize(x);
        sl.putItem(xItem);
        printSortedList(sl);
    }
    cout << "About to make empty..." << endl;
    sl.makeEmpty();
    cout << "After making empty, we have length: " << sl.getLength() << endl;
    cout << "After making empty, the list looks like: " << endl;
    printSortedList(sl);
    cout << "ABout to put 5 in the list for sure..." << endl;
    sl.putItem(item5);
    cout << "After putting item5 (again) we have:" << endl;
    printSortedList(sl);
    cout << "About to put more random integers into the list..." << endl;
    current_time = time(0);
    cout << "The current time for the srand seed is:" << current_time << endl;
    srand(current_time);
    for (int i = 0; i < 5; i++) {
        int x = rand() % 10 - 5;
        cout << "About to insert: " << x << endl;
        ItemType xItem;
        xItem.Initialize(x);
        sl.putItem(xItem);
        printSortedList(sl);
    }
    cout << "ABout to try deleting 20 from the list..." << endl;
    ItemType dItem;
    dItem.Initialize(20);
    sl.deleteItem(dItem);
    cout << "After deleting a non-existent item, the list now looks like:" << endl;
    cout << "And length: " << sl.getLength() << endl;
    printSortedList(sl);
    cout << "ABout to delete the known element (5) from the list..." << endl;
    sl.deleteItem(item5);
    cout << "After deleting the known item 5, we have:" << endl;
    printSortedList(sl);
    cout << "And length:" << sl.getLength() << endl;
    cout << "About to try deleting a bunch of stuff until the list is empty..." << endl;
    current_time = time(0);
    srand(current_time);
    while (sl.getLength() > 0) {
        int lengthBefore = sl.getLength();
        int x = (rand() % 20) - 10;
        ItemType y;
        y.Initialize(x);
        sl.deleteItem(y);
        if (sl.getLength() < lengthBefore) {
            cout << "Deleted " << x << endl;
            printSortedList(sl);
        }
    }
    cout << "Deleted down to empty, now deleting from empty list gives:" << endl;
    sl.deleteItem(item5);
    printSortedList(sl);
}
