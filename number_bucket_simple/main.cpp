#include <iostream>
#include <sstream>
#include <stdexcept>

#include "number_bucket.h"

int main(int argc, char * argv[]) {
    using namespace std;

    stringstream inputSequence;

    inputSequence << "new" << endl
                  << "getSize" << endl
                  << "isEmpty" << endl
                  << "push" << endl << "5" << endl
                  << "getSize" << endl
                  << "isEmpty" << endl
                  << "pop" << endl
                  << "getSize" << endl
                  << "isEmpty" << endl
                  << "pop" << endl
                  << "push" << endl
                  << "7" << endl
                  << "delete" << endl;


    // Begin custom number_bucket code
    NumberBucket * numberBucket;
    string command;
    int value;
    while (inputSequence >> command) {
        try {
            if (command == "new") {
                numberBucket = new NumberBucket();
                cout << "Constructed new NumberBucket. " << endl;
            } else if (command == "delete") {
                delete numberBucket;
                cout << "Destructed NumberBucket. " << endl;
            } else if (command == "isEmpty") {
                cout << "isEmpty() => " << numberBucket->isEmpty() << endl;
            } else if (command == "getSize") {
                cout << "getSize() => " << numberBucket->getSize() << endl;
            } else if (command == "push") {
                inputSequence >> value;
                numberBucket->push(value);
                cout << "Pushed value: " << value << endl;
            } else if (command == "pop") {
                cout << "pop() => " << numberBucket->pop() << endl;
            } else {
                cout << "Unrecognized command: " << command << endl;
            }
        } catch (runtime_error& e) {
            cout << "Caught runtime error: " << e.what() << endl;
        }
    }
}
