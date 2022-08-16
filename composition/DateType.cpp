#include <iostream>

#include "DateType.h"
#include "RelationType.h"

using namespace std;



void DateType::Initialize(int newYear, int newMonth, int newDay) {
    year = newYear;
    month = newMonth;
    day = newDay;
}

int DateType::getYear() const {
    return year;
}

int DateType::getMonth() const {
    return month;
}

int DateType::getDay() const {
    return day;
}

RelationType DateType::compareTo(DateType other) const {
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
