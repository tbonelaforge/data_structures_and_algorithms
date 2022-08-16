#include <iostream>

using namespace std;

void printArray(int a[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int findMinIndex(int a[], int i, int j) {
    int min_index = i;
    for (int k = i + 1; k <= j; k++) {
        if (a[k] < a[min_index]) {
            min_index = k;
        }
    }
    return min_index;
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = findMinIndex(a, i, n - 1);
        swap(a, i, j);
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && a[j] < a[j - 1]) {
            swap(a, j, j - 1);
            j -= 1;
        }
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = n - 1; j > i; --j) {
            if (a[j] < a[j - 1]) {
                swap(a, j, j - 1);
                swapped = true;
            }
        }
        if (!swapped) {
            return;
        }
    }
}


void mergeSortRecursive(int a[], int i, int j, int * temp) {
    cout << "Inside mergeSortRecursive, got called with i = " << i << " and j = " << j << endl;
    if (j - i < 1) {
        cout << "returning early cuz short array..." << endl;
        return;
    }
    int m = (i + j) / 2 + 1;
    cout << "Inside mergeSort, got m of:" << m << endl;
    mergeSortRecursive(a, i, m - 1, temp);
    mergeSortRecursive(a, m, j, temp);
    int k = 0;
    int i_i = i;
    int m_i = m;
    int min_element;
    while (k <= j - i) {
        if (i_i >= m) {
            min_element = a[m_i++];
        } else if (m_i > j) {
            min_element = a[i_i++];
        } else if (a[i_i] < a[m_i]) {
            min_element = a[i_i++];
        } else {
            min_element = a[m_i++];
        }
        cout << "Assigning min_element: " << min_element << endl;
        temp[i + k] = min_element;
        k += 1;
    }
    for (int x = i; x <= j; x++) {
        cout << "Assigning a[" <<  x <<  "] = " << temp[x] << endl;
        a[x] = temp[x];
    }
}


void mergeSort(int a[], int n) {
    cout << "Inside mergeSort, got called...\n";
    int * temp = new int[n];
    mergeSortRecursive(a, 0, n - 1, temp);
    delete[] temp;
}





int main() {
    cout << "Inside SortTest, about to construct a new array for sorting..." << endl;
    int n = 6;
    /*
    int a[6] = {10, -2, 9, 7, 11, 6};
    cout << "Initially, the array looks like:" << endl;
    printArray(a, n);
    cout << endl << "Now sorting with selection sort..." << endl;
    selectionSort(a, n);
    cout << "After sorting we have:" << endl;
    printArray(a, n);
    cout << endl;

    int b[6] = {10, -2, 9, 7, 11, 6};
    cout << "Initially, the array looks like:" << endl;
    printArray(b, n);
    cout << endl << "Now sorting with insertionSort..." << endl;
    insertionSort(b, n);
    cout << "After sorting we have:" << endl;
    printArray(b, n);
    cout << endl;

    int c[6] = {10, -2, 9, 7, 11, 6};
    cout << "Initially, the array looks like:" << endl;
    printArray(c, n);
    cout << endl << "Now sorting with bubbleSort..." << endl;
    bubbleSort(c, n);
    cout << "After sorting we have:" << endl;
    printArray(c, n);
    cout << endl;
    */

    int d[6] = {10, -2, 9, 7, 11, 6};
    //n = 4;
    //int d[4] = {10, -2, 9, 7};
    cout << "Initially, the array looks like:" << endl;
    printArray(d, n);
    cout << endl << "Now sorting with mergeSort..." << endl;
    mergeSort(d, n);
    cout << "After sorting we have:" << endl;
    printArray(d, n);
    cout << endl;
}
