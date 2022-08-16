
#include <iostream>
#include <string>

#include "CountedIntegerQueue.h"

using namespace std;

int main() {
    string command;
    int v;
    CountedIntegerQueue q;
    bool error = false;
    string errorMessage;
    while (!error && (cin >> command).good()) {
        if (command == "enqueue") {
            try {
                if (!(cin >> v).good()) {
                    error = true;
                    errorMessage = "Expected a numeric value following the command 'enqueue'";
                    break;
                }
                q.enqueue(v);
                cout << "Enqueued " << v << endl;
            } catch(FullQueue) {
                cout << "Enqueue: Caught FullQueue Exception" << endl;
            }
        } else if (command == "dequeue") {
            try {
                v = q.dequeue();
                cout << "Dequeued " << v << endl;
            } catch(EmptyQueue) {
                cout << "Dequeue: Caught EmptyQueue Exception" << endl;
            }
        } else if (command == "isFull") {
            cout << "isFull() => " << q.isFull() << endl;
        } else if (command == "isEmpty") {
            cout << "isEmpty() => " << q.isEmpty() << endl;
        } else if (command == "getLength") {
            cout << "getLength() => " << q.getLength() << endl;
        } else {
            cout << "Unrecognized command: " << command << endl;
        }
    }
    if (error) {
        cout << "Invalid input: " + errorMessage << endl;
    }
}
