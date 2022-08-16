#include <iostream>
#include <sstream>
#include <string>

#include "PermutationGenerator.h"

using namespace std;

int main(int argc, char * argv[]) {
    if (argc < 2) {
        cout << "Error: Missing integer 'n'" << endl
             << "Usage: \n" << argv[0] << " 4\n" << endl;
        return 1;
    }
    int n;
    string inputString(argv[1]);
    stringstream inputStream(inputString);
    inputStream >> n;
    PermutationGenerator permGen(n);
    bool notDone = true;
    cout << n << endl;
    while (notDone) {
        permGen.printCurrent();
        notDone = permGen.next();
    }
}
