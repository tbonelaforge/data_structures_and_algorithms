#include <iostream>

#include "Person.h"
#include "DateType.h"

void Person::Initialize(string newName, DateType newBirthdate) {
    name = newName;
    birthdate = newBirthdate;
}

DateType Person::getBirthdate() {
    return birthdate;
}

string Person::getName() {
    return name;
}

