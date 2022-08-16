#ifndef _DATETYPE_H_
#define _DATETYPE_H_

#include <string>
#include "RelationType.h"

using namespace std;

class DateType {
 public:
    DateType() {}
    DateType(int year, int month, int day) : year(year), month(month), day(day) {}
    void Initialize(int newYear, int newMonth, int newDay);
    int getYear() const;
    int getMonth() const;
    string getMonthAsString() const;
    int getDay() const;
    RelationType compareTo(DateType other) const;
    DateType addDays(int days);
 private:
    static string monthIndex[];
    static int monthLookup[];
    int year;
    int month;
    int day;
    static int calculateNumDays(int month, int year);
    static bool isLeapYear(int year);
};

#endif
