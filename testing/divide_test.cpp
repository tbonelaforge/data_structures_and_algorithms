#include "divide.h"
#include <iostream>

int main() {
    using namespace std;
    float result;
    bool error;
    divide(4, 2, result, error);
    cout << "The result of dividing 4 by 2 is:" << result 
         << " And the error is: " << error << endl;
}
