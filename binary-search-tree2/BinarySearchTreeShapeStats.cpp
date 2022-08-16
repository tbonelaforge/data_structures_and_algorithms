
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>
#include <map>
#include <utility>
#include <cmath>
#include <cstdlib>

#include "BinarySearchTree.h"
#include "PermutationGenerator.h"

using namespace std;

int main(int argc, char * argv[]) {
    if (argc < 2) {
        cout << "Error: Missing integer 'n'" << endl
             << "Usage: \n" << argv[0] << " 4\n" << endl;
        exit(1);
    }
    int n;
    string inputString(argv[1]);
    stringstream inputStream(inputString);
    inputStream >> n;
    PermutationGenerator permGen(n);
    bool notDone = true;
    cout << n << endl;
    cout << "height is: " << n - 1 << endl;
    map<string, int> counts;
    map<int, int> scores;
    while (notDone) {
        permGen.printCurrent();
        BinarySearchTree bst;
        for (int i = 0; i < n; i++) {
            bst.insert(permGen.getElement(i));
        }
        string key = bst.toString();
        cout << "About to calculate the score for key: " << key << endl;
        int score = bst.toScore(n - 1);
        cout << "Calculated score of: " << score << endl;
        int current_count = counts[key];
        counts[key] = current_count + 1;

        int current_score = scores[score];
        scores[score] = current_score + 1;
        notDone = permGen.next();
    }
    cout << "After trying all the permutations, the counts look like:" << endl;
    map<string, int>::iterator it;
    for (it = counts.begin(); it != counts.end(); it++) {
        cout << it->first << ':' << it->second << endl;
    }
    cout << endl << "And the scores look like:" << endl;
    map<int, int>::iterator it2;
    for (it2 = scores.begin(); it2 != scores.end(); it2++) {
        cout << it2->first << " : " << it2->second << endl;
    }
}
