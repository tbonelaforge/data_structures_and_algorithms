
#include <iostream>
#include <string>
#include <cstdio>

#include "SortedList.h"

#include <cstdlib>
#include <ctime>

using namespace std;

void printSortedList(SortedList &sl) {
    ItemType x;

    sl.reset();
    cout << "[";
    while (sl.hasNext()) {
        x = sl.getNext();
        x.Print(cout);
        if (sl.hasNext()) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void insertPosTestCase() {
    cout << "About to start from a list of: [1, 3, 3, 3, 4, 5]" << endl;
    SortedList sl_fail(10);
    ItemType x;
    x.Initialize(1);
    sl_fail.putItem(x);
    x.Initialize(3);
    sl_fail.putItem(x);
    x.Initialize(3);
    sl_fail.putItem(x);
    x.Initialize(3);
    sl_fail.putItem(x);
    x.Initialize(4);
    sl_fail.putItem(x);
    x.Initialize(5);
    sl_fail.putItem(x);
    cout << "How does this look?" << endl;
    printSortedList(sl_fail);
    cout << "ABout to insert that fateful 3..." << endl;
    x.Initialize(3);
    sl_fail.putItem(x);
    cout << "Pretty sure I fixed the bug now!!!" << endl;
    printSortedList(sl_fail);
}


int main() {
    cout << "About to construct a new, empty list:" << endl;
    SortedList sl(10);
    cout << "The newly-constructed sorted list has length: " << sl.getLength() << endl;
    cout << "The newly-constructed sorted list has maxLength: " << sl.getMaxLength() << endl;
    cout << "The newly-constructed sorted list hasNext(): " << sl.hasNext() << endl;
    cout << "About to call printSortedList..." << endl;
    printSortedList(sl);
    cout << "About to put the integer 5 into the list..." << endl;
    ItemType item5;
    item5.Initialize(5);
    sl.putItem(item5);
    cout << "Now the length is: " << sl.getLength() << endl
         << "and hasNext(): " << sl.hasNext() << endl << " and the list looks like: " << endl;
    printSortedList(sl);
    cout << "Now trying to print again..." << endl;
    printSortedList(sl);
    cout << "About to put the item 3 in the list " << endl;
    ItemType item3;
    item3.Initialize(3);
    sl.putItem(item3);
    cout << "Now the length is: " << sl.getLength() << endl
         << "and hasNext(): " << sl.hasNext() << endl << " and the list looks like: " << endl;
    printSortedList(sl);
    cout << "About to get the item 5:" << endl;
    ItemType target;
    target.Initialize(5);
    bool found;
    ItemType foundResult = sl.getItem(target, found);
    cout << "Found is: " << found << " and the found item is: ";
    foundResult.Print(cout);
    cout << endl;
    cout << "About to get the item -1234:" << endl;
    target.Initialize(-1234);
    foundResult = sl.getItem(target, found);
    cout << "Found is: " << found << " and the found item is: ";
    foundResult.Print(cout);
    cout << endl;
    cout << "About to put 5 random integers into the list..." << endl;
    time_t current_time = time(0);
    //time_t current_time = 1568585019;
    cout << "About to srand with time:" << current_time << endl;
    srand(current_time);
    for (int i = 0; i < 5; i++) {
        int x = rand() % 6;
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
        cout << "About to put 5 random integers into the list..." << endl;
    current_time = time(0);
    //time_t current_time = 1568585019;
    cout << "About to srand with time:" << current_time << endl;
    srand(current_time);
    for (int i = 0; i < 5; i++) {
        int x = rand() % 6;
        cout << "About to insert: " << x << endl;
        ItemType xItem;
        xItem.Initialize(x);
        sl.putItem(xItem);
        printSortedList(sl);
    }

    cout << "About to test putting too much stuff in the list..." << endl;
    try {
        for (int i = 0; i < 7; i++) {
            int x = rand() % 6 - 3;
            cout << "About to insert: " << x << endl;
            ItemType xItem;
            xItem.Initialize(x);
            sl.putItem(xItem);
            printSortedList(sl);
        }
    } catch (const string& s) {
        cout << "Caught exception: " << s << endl;
    }
    ItemType dItem;
    dItem.Initialize(20);
    cout << "About to try deleting 20 from the list..." << endl;
    sl.deleteItem(dItem);
    dItem.Initialize(5);
    cout << "About to try deleting " << 5 << " from the list..." << endl;
    sl.deleteItem(dItem);
    cout << "Now the list looks like: " << endl;
    printSortedList(sl);
    dItem.Initialize(3);
    cout << "Abou to try deleting " << 3 << " from the list..." << endl;
    sl.deleteItem(dItem);
    cout << "Now the list looks like: " << endl;
    printSortedList(sl);
    cout << "And has length: " << sl.getLength() << endl;
    cout << "Now about to try deleting a bunch of stuff, until the list is empty..." << endl;
    current_time = time(0);
    cout << "About to seed srand with current_time: " << current_time << endl;
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
    cout << "Done!" << endl;
}
