#include <iostream>
#include <fstream>

#include "fraction.h"

int main(int argc, char * argv[]) {
    using namespace std;

    if (argc < 2) {
        cout << "Error: Missing Input Filename" << endl
             << "Usage: \n" << argv[0] << " test_cases.txt\n" << endl;
        return 1;
    }
    ifstream inFile;
    inFile.open(argv[1]);
    if (!inFile) {
        cout << "File " << argv[1] << " was not found." << endl;
        return 1;
    }

    // Begin custom fraction code
    FractionType fraction;
    string command;
    int numerator, denominator;
    while (inFile >> command) {
        //cout << "Read command:" << command << endl;
        if (command == "Initialize") {
            inFile >> numerator >> denominator;
            fraction.Initialize(numerator, denominator);
            cout << "Initialized fraction: ( " 
                 << fraction.getNumerator()
                 << " / "
                 << fraction.getDenominator()
                 << " )\n\n" << endl;
        } else if (command == "isZero") {
            cout << "isZero() => " << fraction.isZero() << endl;
        } else if (command == "isNotProper") {
            cout << "isNotProper() => " << fraction.isNotProper() << endl;
        } else if (command == "convertToProper") {
            cout << "convertToProper() => " 
                 << fraction.convertToProper() 
                 << " ( " << fraction.getNumerator() 
                 << " / " << fraction.getDenominator()
                 << " ) " << endl;
        } else {
            cout << "Unrecognized command: " << command << endl;
        }
    }
    
}
