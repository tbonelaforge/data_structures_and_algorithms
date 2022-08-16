#ifndef _DATETYPE_H_
#define _DATETYPE_H_

#include <string>
#include "RelationType.h"

class DateType {
 public:
    void Initialize(int newYear, int newMonth, int newDay);
    int getYear() const;
    int getMonth() const;
    string getMonthAsString() const;
    int getDay() const;
    RelationType compareTo(DateType other) const;
 private:
    static string monthIndex[13] = {
        "Error",
        "January",
        "February",
    int year;
    int month;
    int day;
};

#endif
