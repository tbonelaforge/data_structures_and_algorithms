#include <iostream>

#include "DateType.h"
#include "RelationType.h"

//using namespace std;

using namespace DateType;

DateType() {
    std::cout << "Inside the no-argument constructor, got called..." << endl;
}

void initialize(int newYear, int newMonth, int newDay) {
    year = newYear;
    month = newMonth;
    day = newDay;
}

int getYear() const {
    return year;
}

int getMonth() const {
    return month;
}

static monthIndex[13] = {
    "Error",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
}

int getDay() const {
    return day;
}

RelationType compareTo(DateType other) const {
    if (year < other.year) {
        return LESS;
    } else if (year > other.year) {
        return GREATER;
    } else if (month < other.month) {
        return LESS;
    } else if (month > other.month) {
        return GREATER;
    } else if (day < other.day) {
        return LESS;
    } else if (day > other.day) {
        return GREATER;
    } else {
        return EQUAL;
    }
}

int main() {
    cout << "About to declare a new variable of type DateType:" << endl;
    DateType d1;
    cout << "About to initialize the dateType..." << endl;
    d1.initialize(2019, 8, 27);
    cout << "About to declare a second variable of type DateType:" << endl;
    DateType d2;
    cout << "About to initialize the second dateType..." << endl;
    d2.initialize(2019, 9, 06);
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
