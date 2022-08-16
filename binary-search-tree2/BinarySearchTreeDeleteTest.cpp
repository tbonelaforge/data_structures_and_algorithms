
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <ctime>

#include "BinarySearchTree.h"
#include "List.hpp"

using namespace std;

void check_ordered(List<int> value_list) {
    bool is_current = false;
    int current;
    while (!value_list.isEmpty()) {
        int v = value_list.dequeue();
        if (!is_current) {
            current = v;
        } else if (v < current) {
            throw "Values out of order: " + to_string(v);
        }
    }
}

int main() {
    time_t current_time = time(0);
    cout << "About to seed the random number generator with the current time:" << current_time << endl;
    srand(current_time);
    int num_nodes = 7;
    cout << "About to randomly insert " << num_nodes << " nodes..." << endl;
    int * data = new int[num_nodes];
    BinarySearchTree bst;
    List<int> insert_order;
    for (int i = 0; i < num_nodes; i++) {
        int x = rand() % 20 - 10;
        cout << "About to insert: " << x << endl;
        data[i] = x;
        insert_order.push(x);
        bst.insert(x);
    }
    cout << "The insert order looks like:" << insert_order << endl;
    cout << "The bst looks like: " << bst.list_values() << endl;
    cout << "The bst has key: " << bst.toString() << endl;
    cout << "Now constructing a random delete order..." << endl;
    for (int i = 0; i < num_nodes; i++) {
        int j = rand() % (num_nodes - i);
        int temp = data[i];
        data[i] = data[i + j];
        data[i + j] = temp;
    }
    cout << "The random delete order is:" << endl;
    for (int i = 0; i < num_nodes; i++) {
        cout << data[i] << ' ';
    }
    cout << "Now deleting..." << endl;
    for (int i = 0; i < num_nodes; i++) {
        bst.remove(data[i]);
        List<int> values_list = bst.list_values();
        cout << "After deleting " << data[i] << " we have: " << endl
             << values_list << endl;
        check_ordered(values_list);
    }
    cout << "Now the bst should be empty:" << bst.list_values() << endl;

    delete data;
}
