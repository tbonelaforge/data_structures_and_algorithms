#include <iostream>

#include "PermutationGenerator.h"

using namespace std;


PermutationGenerator::PermutationGenerator(int n) : n(n) {
    for (int i = 0; i < n; i++) {
        elements[i] = i + 1;
        directions[i + 1] = -1;
        positions[i + 1] = i;
    }
}

void PermutationGenerator::printCurrent() const {
    for (int i = 0; i < n; i++) {
        cout << elements[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void PermutationGenerator::printAll() {
    cout << "elements:" << endl;
    printCurrent();
    cout << endl << "positions:" << endl;
    cout << "  ";
    for (int i = 1; i <= n; i++) {
        cout << positions[i];
        if (i < n) {
            cout << " ";
        }
    }
    cout << endl << "directions:" << endl;
    cout << "  ";
    for (int i = 1; i <= n; i++) {
        cout << directions[i];
        if (i < n) {
            cout << " ";
        }
    }
    cout << endl;

}


void PermutationGenerator::swap(int i, int j) {
    int temp = elements[i];
    elements[i] = elements[j];
    elements[j] = temp;
    positions[elements[i]] = i;
    positions[elements[j]] = j;
}


void PermutationGenerator::switchDirections(int k) {
    for (int x = k + 1; x <= n; x++) {
        directions[x] *= -1;
    }
}


int PermutationGenerator::getAdjacentIndex(int i) {
    int d = directions[elements[i]];
    int j = i + d;
    if (j < 0 || j >= n) {
        return -1;
    }
    return j;
}


int PermutationGenerator::findLargestMobileIndex() {
    for (int k = n; k >= 1; k--) {
        int k_pos = positions[k];
        int j = getAdjacentIndex(k_pos);
        if (j == -1) {
            continue;
        }
        if (elements[j] < k) {
            return k_pos;
        }
    }
    return -1;
}

bool PermutationGenerator::next() {
    int i = findLargestMobileIndex();
    if (i == -1) {
        return false;
    }
    int k = elements[i];
    int j = getAdjacentIndex(i);
    swap(i, j);
    switchDirections(k);
    return true;
}

int PermutationGenerator::getElement(int i) const {
    return elements[i];
}
