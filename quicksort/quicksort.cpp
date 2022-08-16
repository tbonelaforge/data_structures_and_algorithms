
#include <iostream>

using namespace std;

void print_array(int * a, int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void swap(int * a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int split(int * a, int i, int j) {
    int original_i = i;
    int pivot_value = a[original_i];
    while (i <= j) {
        if (a[i] > pivot_value) {
            swap(a, i, j);
            j -= 1;
        } else {
            i += 1;
        }
    }
    swap(a, original_i, j);
    return j;
}


void split2(int a[], int lo, int hi, int& split_point1, int& split_point2) {
    int m = (lo + hi) / 2;
    int splitVal = a[m];
    swap(a, m, hi);
    int i = lo; // a[lo..i] < splitVal
    int k = hi; // a[k..(j -1)] == splitVal
    int j = hi + 1; // a[j...hi] > splitVal
    while (i < k) {
        if (a[i] > splitVal) {
            swap(a, i, --j);
        } else if (a[i] == splitVal) {
            swap(a, i, --k);
        } else {
            i++;
        }
    }
    split_point1 = k - 1;
    split_point2 = j;
}

void quicksort(int * a, int i, int j) {
    if (i > j) {
        return;
    }
    int split_point = split(a, i, j);
    quicksort(a, i, split_point - 1);
    quicksort(a, split_point + 1, j);
}

void quicksort2(int * a, int i, int j) {
    if (i > j) {
        return;
    }
    int split_point1, split_point2;
    split2(a, i, j, split_point1, split_point2);
    if (split_point1 > i) {
        quicksort2(a, i, split_point1);
    }
    if (split_point2 < j) {
        quicksort2(a, split_point2, j);
    }
}
/*
int main() {
    int test_array[7] = { 5, 2, 7, 9, 2, 8, 0 };
    int n = 7;
    cout << "About to test the split function on array..." << endl;
    print_array(test_array, n);
    cout << "About to split the array..." << endl;
    int split_result = split(test_array, 0, n - 1);
    cout << "The split_result is: " << split_result << endl;
    cout << "Now the array looks like:" << endl;
    print_array(test_array, n);
    cout << endl << "About to test split on an array of 3 elements..." << endl;
    int test_array2[3] = { 5, 2, 1 };
    int n2 = 3;
    split_result = split(test_array2, 0, n2 - 1);
    cout << "The split_result for the array of 3 elements is: " << split_result << endl;
    cout << "The resulting array is: " << endl;
    print_array(test_array2, n2);
    cout << endl;
    cout << endl << "About to test split on an array of 2 elements..." << endl;
    int test_array3[2] = { 5, 2 };
    int n3 = 2;
    split_result = split(test_array3, 0, n3 - 1);
    cout << "The split_result for the array of 2 elements is: " << split_result << endl;
    cout << "The resulting array is: " << endl;
    print_array(test_array3, n3);
    cout << endl;
    cout << endl << "About to test split on an array of 1 elements..." << endl;
    int test_array4[1] = { 5 };
    int n4 = 1;
    split_result = split(test_array4, 0, n4 - 1);
    cout << "The split_result for the array of 1 elements is: " << split_result << endl;
    cout << "The resulting array is: " << endl;
    print_array(test_array4, n4);
    cout << endl;

    int test_array[8] = { 3, 6, 2, 7, 2, 8, 3, 2 };
    int n = 8;
    cout << "About to try sorting the following array..." << endl;
    print_array(test_array, n);
    cout << endl;
    cout << "Sorting ..." << endl;
    quicksort(test_array, 0, n - 1);
    cout << "After sorting, we have: " << endl;
    print_array(test_array, n);

    int test_array[7] = { 9, 2, 7, 9, 12, -8, 10 };
    int n = 7;
    cout << "About to test the split2 function on array..." << endl;
    print_array(test_array, n);
    cout << "About to split the array..." << endl;
    int split_point1, split_point2;
    split2(test_array, 0, n - 1, split_point1, split_point2);
    cout << "After using split2, we have split_point1, split_point2:\n" << endl;
    cout << "split_point1: " << split_point1 << endl
         << "split_point2: " << split_point2 << endl;
    cout << "Now the array looks like:" << endl;
    print_array(test_array, n);

    
    int test_array[7] = { 9, 2, 7, 9, 12, -8, 10 };
    int n = 7;
    cout << "About to quicksort2 on the array..." << endl;
    print_array(test_array, n);
    quicksort2(test_array, 0, n - 1);
    cout << "After quicksort2, the array looks like:" << endl;
    print_array(test_array, n);
    

    int test_array[7] = {-8, 2, 7, 9, 9, 12, 10};
    int n = 7;
    cout << "About to test quicksort2 on the array..." << endl;
    print_array(test_array, n);
    quicksort2(test_array, 0, 2);

}
*/
