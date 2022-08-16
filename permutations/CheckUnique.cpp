#include <iostream>

#include <vector>

#include <set>

#include <utility>

using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void printVec(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

bool checkUnique(vector<int> permVec, set< vector<int> >& unique) {
    pair<set< vector<int> >::iterator, bool> insertResult;
    insertResult = unique.insert(permVec);
    return insertResult.second;
}

int main() {
    int x;
    int n;
    set< vector<int> > unique;
    cin >> n;
    if (!n || n > 25) {
        cout << "Invalid input! Expected first line to be an integer greater than 0 and less than or equal to 25." << endl;
        return 1;
    }
    cout << "Checking permutation output for  n = " << n << endl;
    vector<int> permVec(n);
    int i = 0;
    int l = 0;
    int n_factorial = factorial(n);
    while (l < n_factorial) {
        if (i >= n) {
            if (!checkUnique(permVec, unique)) {
                cout << "Duplicate permutation found: " << endl;
                printVec(permVec);
                return 1;
            }
            l += 1;
            i = 0;
        }
        cin >> x;
        if (!cin.good()) {
            break;
        }
        permVec[i] = x;
        i += 1;
    }
    if (l < n_factorial) {
        cout << "Not enough permutations were generated: " << endl
             << "Got: " << l << endl
             << "Expected: " << n_factorial << " permutations." << endl;
    } else if (i > 0) {
        cout << "Too much output was generated: " << endl
             << "Expected: " << n_factorial << " permutations." << endl;
    }
    cout << "Success! " << endl
         << "Checked " << unique.size() << " unique permutaions." << endl;
}
