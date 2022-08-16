#include <iostream>
#include <cstring>
using namespace std;

struct CarType {
    int year;
    char maker[10];
    float price;
};

void printCar(CarType car) {
    cout << "The year is: " << car.year << endl;
    //cout << "The maker is: " << string(car.maker) << endl;
    
    for (int i = 0; i < 10; i++) {
        //cout << "Printing char # " << i << " of the maker array";
        //cout << car.maker[i] << " <= " << int(car.maker[i]) << " ";
        cout << "<= " << int(car.maker[i]) << " ";
    }
    
    cout << endl;
    cout << "The price is: " << car.price << endl;
}

void changeYear(CarType carToChange, int year) {
    carToChange.year = year;
}

void changePrice(CarType carToChange, float price) {
    carToChange.price = price;
}

void changeMaker(CarType carToChange, const char maker[]) {
    cout << "Inside changeMaker, about to mess with the carToChange.maker field, which is: " << (void *) carToChange.maker << endl;
    cout << "Inside changeMaker, the maker reads as:" << endl;
    printCar(carToChange);
    strncpy(carToChange.maker, maker, 10);
    cout << "Inside changeMaker, after changing the carToChange, it reads as:\n" << endl;
    printCar(carToChange);
}

void reallyChangeCar(CarType& carToChange, int year, float price, const char maker[]) {
    cout << "Inside reallyChangeCar, about to mess with the maker field, which is: " << (void *) carToChange.maker << endl;
    carToChange.year = year;
    carToChange.price = price;
    strncpy(carToChange.maker, maker, 10);
}

int main() {

    cout << "About to create a CarType..." << endl;
    CarType myCar;
    cout << "The newly-constructed CarType probably has junk values: \n" << endl;
    printCar(myCar);
    cout << "Now setting the values of the car...";
    myCar.year = 2019;
    strncpy(myCar.maker, "JAGUAR", 10);
    myCar.price = 27890.75;
    cout << "After attempting to set the values of the new car, we have it looking like:" << endl;
    printCar(myCar);

    cout << "About to change year:" << endl;
    changeYear(myCar, 1979);
    cout << "After changing the year, we have original car: " << endl;
    printCar(myCar);

    cout << "ABout to change price:" << endl;
    changePrice(myCar, 28790.57);
    cout << "After changing the price, we have original car: " << endl;
    printCar(myCar);

    cout << "ABout to change maker: " << (void * ) myCar.maker << endl;
    changeMaker(myCar, "Hi");

    cout << "After changing the maker, we have: " << endl;
    printCar(myCar);

    cout << "About to REALLY change the car... " << endl;
    reallyChangeCar(myCar, 4456, 234.234, "Hello, bruh");
    cout << "After really changing the car, it looks like:\n";
    printCar(myCar);
    cout << myCar.maker << endl;
}
