
#include <iostream>

using namespace std;

int main() {
    /*
    cout << "About to try dynamic 2d array..." << endl;
    char ** p = new char*[3];
    for (int i = 0; i < 3; i++) {
        p[i] = new char[4];
        for (int j = 0; j < 4; j++) {
            p[i][j] = 'a' + 4 * i + j;
        }
    }
    cout << "Just set up the new 2d-array..." << endl;
    cout << "It looks like: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << p[i][j];
        }
        cout << endl;
    }
    cout << endl << "And that is all.." << endl;
    */
    cout << "About to test the initialization of a 2d-array, with fewer rows and columns..." << endl;
    char test_array[4][10] = {
        { 'a', 'b', 'c', 'd', 'e' },
        { 'a', 'b', 'c', 'd', 'e' },
        { 'a', 'b', 'c', 'd', 'e' },
        { 'a', 'b', 'c', 'd', 'e' }
    };
    cout << "Made it past the initialization..." << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << test_array[i][j];
        }
        cout << endl;
    }
}
