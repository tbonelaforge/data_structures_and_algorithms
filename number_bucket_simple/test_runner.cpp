#include <iostream>
#include <fstream>

#include "number_bucket.h"

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

    // Begin custom number_bucket code
    NumberBucket * numberBucket;
    string command;
    int value;
    cout << "Before doing anything, the numberBucket ptr is: " << numberBucket << endl;
    while (inFile >> command) {
        //cout << "Read command:" << command << endl;
        if (command == "new") {
            numberBucket = new NumberBucket();
            cout << "Constructed new NumberBucket: " << numberBucket << " with size: " << numberBucket->getSize() << endl;
        } else if (command == "delete") {
            delete numberBucket;
            cout << "Destructed NumberBucket: ";
        } else {
            cout << "Unrecognized command: " << command << endl;
        }
    }
    
}
