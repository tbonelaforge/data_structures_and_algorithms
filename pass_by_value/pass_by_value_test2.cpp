#include <iostream>

using namespace std;

class Node;
class OtherNode;

class Node {
    
private:
    int value;
    OtherNode p;
};




int main() {
    cout << "Inside the main function, about to try and construct a circular object..." << endl;
    Node n;
}
