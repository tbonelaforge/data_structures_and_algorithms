
#include <iostream>

#include "DateType.h"

#include "RelationType.h"

using namespace std;

int main() {
    cout << "About to declare a new variable of type DateType:" << endl;
    DateType d1;
    cout << "About to initialize the dateType..." << endl;
    d1.Initialize(2019, 8, 27);
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
}
