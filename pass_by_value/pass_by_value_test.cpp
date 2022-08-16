#include <string>
#include <iostream>

using namespace std;

int personCount = 0;
int carCount = 0;

class Person {
public:
    Person() {
        firstName = "";
        lastName = "";
        ssn = ++personCount;
    }
    Person(string first, string last) {
        firstName = first;
        lastName = last;
        ssn = ++personCount;
    }
    string getFullName() {
        return firstName + lastName;
    }
    int getSSN() {
        return ssn;
    }
    void setLastName(string newLastName) {
        lastName = newLastName;
        cout << "Inside setLastName, now the fullname is:\n" << getFullName() << endl;
    }
private:
    string firstName;
    string lastName;
    int ssn;
};

class Car {
public:
    Car(string make, string model): make(make), model(model) {
        vin = ++ carCount; 
    }
    void setDriver(Person newDriver) {
        driver = newDriver;
    }
    Person getDriver() {
        return driver;
    }
    string getMake() {
        return make;
    }
    string getModel() {
        return model;
    }
    int getVin() {
        return vin;
    }
private:
    string make;
    string model;
    int vin;
    Person driver;
};

void tryToChange(Car car) {
    Person p = car.getDriver();
    p.setLastName("Poopface");
    cout << "Inside tryToChange, after p.setLastName, we now have p.fullname: " << p.getFullName() << endl;
    car.setDriver(p);
    cout << "Inside tryToChange, now the car has driver:" << car.getDriver().getFullName() << endl;
}

int main() {
    cout << "About to try the default constructor for a Person..." << endl;
    Person p0;
    
    cout << "About to construct a new person..";
    Person p1("Mike", "Hunt");
    cout << "The new person's fullname is: " << p1.getFullName() << endl;
    cout << "The new person's ssn is: " << p1.getSSN() << endl;
    
    cout << "About to construct a new car." << endl;
    Car c1("Honda", "Accord");
    c1.setDriver(p1);
    cout << "The car has make, model: " << c1.getMake() << ", " << c1.getModel() << endl;
    cout << "The car has driver: " << c1.getDriver().getFullName() << " : " << c1.getVin() << endl;
    cout << "About to call tryToChange on the car, by value" << endl;
    tryToChange(c1);
    cout << "After calling the tryToChange, we now have c1 driver:" << c1.getDriver().getFullName() << endl;
    
}
