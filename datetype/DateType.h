#ifndef _DATETYPE_H_
#define _DATETYPE_H_

#include "RelationType.h"

class DateType {
 public:
    DateType();
    void initialize(int newYear, int newMonth, int newDay);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    RelationType compareTo(DateType other) const;
 private:
    int year;
    int month;
    int day;
};

#endif
