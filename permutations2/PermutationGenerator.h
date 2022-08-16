#ifndef PERMUTATIONGENERATOR_H
#define PERMUTATIONGENERATOR_H

//each Element is a record of a number and a direction
struct Element {
    bool pointsLeft;    //false: points right
        
    int num;    
        
    void swapElement(Element &);    //helper function that swaps Elements
};

class PermutationGenerator {
 public:
    
    PermutationGenerator(int n); // Initializes first permutation. Exception if n < 0 or n > 25
    
    ~PermutationGenerator();    //Destructor

    bool next(); // Performs a swap and returns true. Return false if done.

    void printPermutation(); // Writes the permutaion to stdout, e.g. "1 3 2"

    Element getElement(int i); // Returns Element at index. Exception if 'i' out of bounds.
    
    unsigned long long getPermCount();  //Returns count of permutations so far

 private: 

    int n;    //input

    Element* permutation;    //pointer to array of permutation of elements; capapcity = n
    
    bool hasMobile;    //status of remaing mobile element
    
    int mobileIndex;    //index of current mobile element
    
    int mobileNum;    //value of mobile element
    
    unsigned long long permCount;    //count of permutations so far

};
#endif
