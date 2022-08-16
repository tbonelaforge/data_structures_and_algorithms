#include <iostream>
#include <cstring>

using namespace std;

struct CarType {
    int year;
    char * maker;
    float price;
};

void printCar(CarType car) {
    cout << "The year is: " << car.year << endl;
    cout << "The maker is: " << car.maker << endl;
    cout << "The price is: " << car.price << endl;
}


void passByValue(CarType car) {
    cout << "Inside passByValue, got car:" << (void*) &car << endl;
    cout << "The car passed by value has maker:" << (void* ) car.maker << endl;
    car.maker = new char[10];
    strncpy(car.maker, "ppoop", 10);
}

int main() {
    cout << "About to create a CarType..." << endl;
    CarType myCar;
    //char * p = new char[10];
    myCar.maker = new char[10];
    strncpy(myCar.maker, "JAGUAR", 10);
    cout << "The newly-constructed CarType probably has junk values: " << endl;
    printCar(myCar);
    cout << "The car is" << (void *) &myCar << endl;
    cout << "About to pass the car by value..." << endl;
    cout << "The maker is: " << (void *) myCar.maker << endl;
    passByValue(myCar);
    cout << "After passby value, the car is:"
}
