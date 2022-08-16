#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>

#include "DateType.h"

using namespace std;
class Person {
 public:
    void Initialize(string newName, DateType newBirthdate);
    DateType getBirthdate();
    string getName();
 private:
    string name;
    DateType birthdate;   
};

#endif
