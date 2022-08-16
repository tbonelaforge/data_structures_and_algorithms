#include <fstream>
#include <stdio.h>

int main() {
    using namespace std;

    char c;
    ifstream inData;
    inData.open("input.dat");
    while (!inData.eof()) {
        inData.get(c);
        printf("Got Character(in hex): %x\n", c);
    }
}
