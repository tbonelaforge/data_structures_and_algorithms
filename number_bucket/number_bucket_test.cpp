#include <iostream>
#include <stdexcept>

#include "number_bucket.h"
#include "node.h"

int main() {
    using namespace std;
    cout << "Inside the main function, about to construct numberBucket1" << endl;
    NumberBucket numberBucket1(1);
    cout << "About to push three values onto numberBucket1..." << endl;
    numberBucket1.push(11);
    numberBucket1.push(12);
    numberBucket1.push(13);
    try {
        cout << "Inside the try block, I'm about to construct numberBucket2...";
        NumberBucket numberBucket2(2);
        cout << "The values of the newly-constructed number_bucket are:" << endl
             << "head = " << numberBucket2.getHead() << endl
             << "size = " << numberBucket2.getSize() << endl;
        cout << "That is all..." << endl;
        cout << "The initial value of the isEmpty call is: " 
             << numberBucket2.isEmpty() << endl;
        cout << "Now I am going to push a new value(3) onto the number bucket." << endl;
        numberBucket2.push(3);
        cout << "Now we have : " << endl
             << "head = " << numberBucket2.getHead() << endl
             << "size = " << numberBucket2.getSize() << endl;
        cout << "After pushing, the isEmpty call gives:" << endl;
        cout << numberBucket2.isEmpty() << endl;
        cout << "I'm about to pop a value from the stack." << endl;
        int popped = numberBucket2.pop();
        cout << "Popped value: " << popped << endl;
        cout << "After popping the last value, we have isEmpty() => "
             << numberBucket2.isEmpty() << endl;
        cout << "Now I'm going to pop from empty list!!!\n" << endl;
        popped = numberBucket2.pop();
    } catch (runtime_error& e) {
        cout << "Caught runtime error: " << e.what() << endl;
    }
    cout << "After the try block, still running code!!!" << endl;
}
