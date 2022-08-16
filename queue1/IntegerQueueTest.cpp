#include <iostream>

#include "IntegerQueue.h"

using namespace std;

int main() {
    cout << "About to construct a new queue..." << endl;
    IntegerQueue q;
    cout << "About to enqueue an element..." << endl;
    q.enqueue(1);
    q.enqueue(2);
    cout << "About to dequeue an element..." << endl;
    int v = q.dequeue();
    cout << v;
    v = q.dequeue();
    cout << v << endl;
}
