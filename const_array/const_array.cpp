#include <iostream>

void tryToChange(const int target[]) {
    target[0] = 5;
}


int main() {
    using namespace std;
    int test_array[10];
    cout << "About to try and change the first element of the array:\n" << endl;
    tryToChange(test_array);
}
