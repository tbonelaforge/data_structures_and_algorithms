#include <iostream>
#include "PermutationGenerator.h"
#include <vector>
using namespace std;



int main()
{
	int n;
	int x=0;
        cout << "Enter a number from 1 to 25" << endl;
	cin >> n;
	if (!n || n > 25) {
		cout << "Invalid input! Expected first line to be an integer greater than 0 and less than or equal to 25." << endl;
		return 1;
	}
        PermutationGenerator tester(n);

	if (n == 3) {
		int check[6][3] = {
			1, 2, 3,
			1, 3, 2,
			3, 1, 2,
			3, 2, 1,
			2, 3, 1,
			2, 1, 3, };
		
		int input[6][3];
		for (int j=0;j<6;j++){
			for (int i = 0; i < 3; i++) {
				input[j][i] = tester.getElement(i).num;
				
			}tester.next();
		}

		for (int j = 0; j < 6; j++) {
			for (int i = 0; i < 3; i++) {
				cout << input[j][i] << " ";
				}
		}

		cout << endl;

		for (int j = 0; j < 6; j++) {
			for (int i = 0; i < 3; i++) {
				cout << check[j][i] << " ";
			}
		}
		
		for (int j=0;j<6;j++){
			for (int i = 0; i <3; i++) {
				if (check[j][i] != input[j][i]) {
					cout << "Error permutations not in order" << endl;
					return 1;
				}
			}
		}
		cout << "Permutation is in order" << endl;

	}


	
	return 0;
	

}
