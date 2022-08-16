#include <iostream>

#include "PriorityQueue.hpp"

using namespace std;
int main() {
    int maxElements = 7;
    cout << "About to construct a new priority queue for integers with max Elements: " << maxElements << endl;
    PriorityQueue<int> pq(7);
    cout << "Made it past the construction of the priority queue" << endl;
    cout << "About to enqueue the number 5" << endl;
    pq.enqueue(5);
    cout << "About to enqueue the number 7" << endl;
    pq.enqueue(7);
    cout << "About to enqueue the number 2" << endl;
    pq.enqueue(2);
    cout << "About to enqueue the number 12" << endl;
    pq.enqueue(12);
    cout << "About to dequeue the numbers..." << endl;
    int test;
    while (!pq.isEmpty()) {
        test = pq.dequeue();
        cout << "Dequeued: " << test << endl;
    }
    return 0;
}
