#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>

#include "quicksort.h"

using namespace std;

bool is_in_order(int a[], int n) {
    int current;
    bool current_defined = false;
    for (int i = 0; i < n; i++) {
        if (current_defined && a[i] < current) {
            return false;
        }
        current = a[i];
        current_defined = true;
    }
    return true;
}

int pick_one(int lo, int hi) {
    int range = hi - lo + 1;
    int r = rand() % range;
    return lo + r;
}

int DUP_ODDS = 4;
int SWAP_ODDS = 10;

void fill_test_arrays(int a[], int b[], int n, int range) {
    if (range <= n) {
        throw "Range of " + to_string(range) + " not big enough for arrays of size " + to_string(n);
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            a[i] = pick_one(0, range - n);
        } else {
            if ((rand() % DUP_ODDS) == 0) {
                a[i] = a[i - 1];
            } else {
                a[i] = pick_one(a[i - 1] + 1, range - (n - i));                
            }
        }
        b[i] = a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (rand() % SWAP_ODDS == 0) {
            int j = pick_one(0, n - 1);
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}

void test_both_quicksorts(int n, int range, double times1[], double times2[], int test) {
    int * a = new int[n];
    int * b = new int[n];
    fill_test_arrays(a, b, n, range);
    chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
    quicksort(a, 0, n - 1);
    chrono::time_point<chrono::system_clock> end1 = chrono::system_clock::now();
    chrono::duration<double> diff = end1 - start;
    if (!is_in_order(a, n)) {
        cout << "quicksort failed!" << endl;
        exit(1);
    }
    times1[test] = diff.count();
    chrono::time_point<chrono::system_clock> start2 = chrono::system_clock::now();
    quicksort2(b, 0, n - 1);
    chrono::time_point<chrono::system_clock> end2 = chrono::system_clock::now();
    diff = end2 - start2;
    if (!is_in_order(b, n)) {
        cout << "quicksort2 failed!" << endl;
        exit(1);
    }
    times2[test] = diff.count();
    delete[] a;
    delete[] b;
}



int main(int argc, char * argv[]) {
    int n = 70;
    if (argc >=2) {
        n = atoi(argv[1]);
    }
    //int n = 7;

    int range = 200;
    int num_tests = 10;
    time_t current_time = time(0);
    cout << "About to srand with current_time: " << current_time << endl;
    srand(current_time);
    double * times1 = new double[num_tests];
    double * times2 = new double[num_tests];
    cout << "Performing " << num_tests << " tests of " << n << "-element arrays..." << endl;
    for (int test = 0; test < num_tests; test++) {
        test_both_quicksorts(n, range, times1, times2, test);
    }
    double avg_time1 = 0.0;
    double avg_time2 = 0.0;
    for (int test = 0; test < num_tests; test++) {
        avg_time1 += times1[test];
        avg_time2 += times2[test];
    }
    avg_time1 /= num_tests;
    avg_time2 /= num_tests;
    cout << "The average for quicksort1 was: " << avg_time1 << endl;
    cout << "The average for quicksort2 was: " << avg_time2 << endl;
    delete[] times1;
    delete[] times2;
    /*
    for (int i = 0; i < n; i++) {
        a[i] = rand() % range - range / 2;
        b[i] = a[i];
    }
    cout << "The randomly-generated array looks like:" << endl;
    print_array(a, n);
    cout << endl << "The result of is_in_order is: " 
         << is_in_order(a, n) << endl;

    cout << "About to run quicksort on array a..." << endl;
    quicksort(a, 0, n - 1);
    cout << "After quicksort, the array now looks like:" << endl;
    print_array(a, n);
    cout << "Sorted = " << is_in_order(a, n) << endl;
    cout << "About to run quicksort2 on array b..." << endl;
    quicksort2(b, 0, n - 1);
    cout << "After quicksort2, the array now looks like:" << endl;
    print_array(b, n);
    cout << "Sorted = " << is_in_order(a, n) << endl;



    delete[] a;
    delete[] b;
    */
}
