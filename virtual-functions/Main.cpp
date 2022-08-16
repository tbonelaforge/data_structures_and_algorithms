#include <iostream>

using namespace std;
class A {
public:
    void foo() { cout << "A.foo got called..." << endl; } 
};

class B : public A {
public:
    virtual void bar() { cout << "B.bar got called..." << endl; }
};

int main() {
    cout << "About to Construct a B object..." << endl;
    B b;
    cout << "NO PROBLEM CONSTRUCTING" << endl;
    cout << "ABout to call b.bar..." << endl;
    b.bar();
    cout << "Success..." << endl;
}
