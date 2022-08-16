#include "PermutationGenerator.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    string str;
    
    if (argc > 1) str = argv[1];
    else return 1;
    
    int in = stoi(str);
    cout << in << endl;
    try { PermutationGenerator pg(in); } 
    catch (const char* e) {
        cout << e << endl;
        return 1;
    }

    PermutationGenerator pg(in);
    do {
        pg.printPermutation();
    } while (pg.next());
    if (pg.getPermCount() > 1) pg.printPermutation();

}
