#include <iostream>

typedef char Board[3][3];

using namespace std;

void printBoard(Board b) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ' ' <<  b[i][j] << ' ';
            if (j < 2) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "-----------" << endl;
        }
    }
}

int main() {
    cout << "Inside main, about to declare a new board..." << endl;
    Board b = {'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q'};
    cout << "Now the board looks like: " << endl;
    printBoard(b);
}
