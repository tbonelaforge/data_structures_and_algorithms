#include <iostream>

#include "PermutationGenerator.h"

using namespace std;

int main() {
    cout << "About to construct a new PermutationGenerator..." << endl;
    PermutationGenerator pgen(3);
    cout << "Initial permutation:" << endl;
    pgen.printCurrent();
    cout << "next gives: " << pgen.next() << endl;
    pgen.printCurrent();
    cout << "next gives: " << pgen.next() << endl;
    pgen.printCurrent();
    cout << "next gives: " << pgen.next() << endl;
    pgen.printCurrent();
    cout << "next gives: " << pgen.next() << endl;
    pgen.printCurrent();
    cout << "next gives: " << pgen.next() << endl;
    pgen.printCurrent();
    cout << "next gives: " << pgen.next() << endl;
    pgen.printCurrent();
    cout << "next gives: " << pgen.next() << endl;
    pgen.printCurrent();
    /*
    int i, j;
    pgen.printAll();
    cout << "The largest mobile index is: " << endl;
    i = pgen.findLargestMobileIndex();
    cout << i << endl;
    cout << "The adjacent index is: " << endl;
    j = pgen.getAdjacentIndex(i);
    cout << j << endl;
    cout << "ABout to swap " << i << " " << j << endl;
    pgen.swap(i, j);
    cout << "Now it looks like: " << endl;
    pgen.printAll();
    */
    /*
    cout << "About to swap indices 2, 1" << endl;
    pgen.swap(2, 1);
    cout << "After swapping, we have: " << endl;
    pgen.printAll();
    cout << "About to switch directions, with k = 1" << endl;
    pgen.switchDirections(1);
    cout << "After switching directions, we have: " << endl;
    pgen.printAll();
    cout << "About to getAdjacent(0)" << endl;
    cout << pgen.getAdjacent(0) << endl;
    cout << "About to getAdjacent(1)" << endl;
    cout << pgen.getAdjacent(1) << endl;
    */
}
