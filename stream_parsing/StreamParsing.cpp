#include <iostream>

#include <array>

using namespace std;
int main() {
    cout <<  "About to read some integers..." << endl;
    int x;
    int n;
    cin >> n;
    cout << "Read n = " << n << endl;
    array<int, n> a;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cout << "Read x: " << x << endl;
        a[i] = x;
    }
}
