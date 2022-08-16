
#include <iostream>

#include "DateType.h"

#include "RelationType.h"

using namespace std;

void printDateType(DateType d) {
    cout << "year = " << d.getYear()
          << ", month = " << d.getMonth() << "(" << d.getMonthAsString() << ")"
          << ", day = " << d.getDay() << endl;
}

int main() {
    cout << "About to declare a new variable of type DateType:" << endl;
    DateType d1;
    cout << "Made it past the constructor..." << endl;
    cout << "About to initialize the dateType..." << endl;
    d1.Initialize(2019, 8, 27);
    cout << "We have: " << endl;
    printDateType(d1);

    cout << "About to declare a second variable of type DateType:" << endl;
    DateType d2;
    cout << "About to initialize the second dateType..." << endl;
    d2.Initialize(2019, 9, 06);
    cout << "About to compare dateType to dateType2:" << endl;
    switch (d1.compareTo(d2)) {
    case LESS:
        cout << "d1 is less than d2" << endl;
        break;
    case EQUAL:
        cout << "d1 is equal to d2" << endl;
        break;
    case GREATER:
        cout << "d1 is greater than d2" << endl;
        break;
    default:
        cout << "Unrecognized comparison result: " << d1.compareTo(d2);
        break;
    }

    cout << "Today is 2019/09/10. About to add 45 days" << endl;
    DateType today(2019, 9, 10);
    cout << "Printing today gives: " << endl;
    printDateType(today);
    cout << "About to add 45 days to today..." << endl;
    DateType today45 = today.addDays(45);
    cout << "The result: " << endl;
    printDateType(today45);
    cout << "About to add 365 days to today..." << endl;
    DateType today365 = today.addDays(365);
    cout << "The result: " << endl;
    printDateType(today365);
}
