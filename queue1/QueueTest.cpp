#include <iostream>

#include "Queue.hpp"

using namespace std;

int main() {
    cout << "About to construct 3 different queues for three different item types...\n";
    Queue<int> iq;
    Queue<float> fq;
    Queue<char> cq;
    cout << "About to enqueue 1 and 2 to the integer queue..." << endl;
    iq.enqueue(1);
    iq.enqueue(2);
    cout << iq.dequeue() << " " << iq.dequeue() << endl;
    cout << "ABout to enqueue 1.5 and 2.75 to the float queue..." << endl;
    fq.enqueue(1.5);
    fq.enqueue(2.75);
    cout << fq.dequeue() << " " << fq.dequeue() << endl;
    cout << "About to enqueue 'a' and 'b' to the character queue..." << endl;
    cq.enqueue('a');
    cq.enqueue('b');
    cout << cq.dequeue() << " " << cq.dequeue() << endl;
}
