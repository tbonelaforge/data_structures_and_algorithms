
#include <iostream>
#include <string>

#include "Queue2.h"

using namespace std;

int main() {
    string command;
    int v;
    Queue2 q;
    bool error = false;
    string errorMessage;
    while (!error && (cin >> command).good()) {
        if (command == "enqueue") {
            if (!(cin >> v).good()) {
                error = true;
                errorMessage = "Expected a numeric value following the command 'enqueue'";
                break;
            }
            q.enqueue(v);
            cout << "Enqueued " << v << endl;
        } else if (command == "dequeue") {
            try {
                v = q.dequeue();
                cout << "Dequeued " << v << endl;
            } catch(EmptyQueue) {
                cout << "Dequeue: Caught EmptyQueue Exception" << endl;
            }
        } else if (command == "isEmpty") {
            cout << "isEmpty() => " << q.isEmpty() << endl;
        } else if (command == "print") {
            q.print(cout);
            cout << endl;
        } else {
            cout << "Unrecognized command: " << command << endl;
        }
    }
    if (error) {
        cout << "Invalid input: " + errorMessage << endl;
    }
}
