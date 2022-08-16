
class PermutationGenerator {
 public:
    PermutationGenerator(int n); // Initializes first permutation. Exception if n < 0 or n > 25

    bool next(); // Performs a swap and returns true. Return false if done.

    void printCurrent() const; // Writes the current permutaion to stdout, e.g. "1 3 2"

    int getElement(int i) const; // Returns elements[i]. Exception if 'i' out of bounds.

    void swap(int i, int j);

    void switchDirections(int k);

    int getAdjacentIndex(int i);

    int findLargestMobileIndex();

    void printAll();

 private: // (Subject to change!)


    int n;

    int elements[25];

    int positions[26];

    int directions[26];


};
