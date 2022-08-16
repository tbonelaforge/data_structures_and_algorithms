/*    UML
----------------------------
Element
----------------------------
+ pointsLeft: bool
+ num: int

+ swapElement(e: Element): void
----------------------------


----------------------------
PermutationGenerator
----------------------------
- n: int
- permutation: Element*
- hasMobile: bool
- mobileIndex: int
- mobileNum: int
- permCount: unsigned long long
----------------------------
+ PermutationGenerator(n: int)
+ ~PermutationGenerator()

+ next(): bool
+ printPermutation(): void
+ getElement(i: int): Element
+ getPermCount(): unsigned long long
----------------------------
*/

#include "PermutationGenerator.h"
#include <iostream>
using namespace std;

void Element::swapElement(Element &e) {
    Element swapper = e;
    e = *this;
    *this = swapper;
}
PermutationGenerator::~PermutationGenerator() {
    delete[] permutation;
}
unsigned long long PermutationGenerator::getPermCount() {
    return permCount;
}
Element PermutationGenerator::getElement(int i) {
    if (n<0 || n>25) throw "Input out of bounds! (1 - 25)";
    
    return permutation[i];
}
void PermutationGenerator::printPermutation() {
    for (int i = 0; i < n; ++i)
        cout << permutation[i].num << " ";
        
    cout << endl;
}
PermutationGenerator::PermutationGenerator(int n) {
    if (n<1 || n>25) throw "Input out of bounds! (1 - 25)";
    
    if (n == 1) {
        permutation = new Element[n];
        permutation[0].num = 1;
        permutation[0].pointsLeft = true;
        hasMobile = false;
        permCount = 1;
        this->n = n;
        return;
    }
    
    permutation = new Element[n];
    hasMobile = true;
    permCount = 1;
    this->n = n;
    mobileIndex = n - 1;
    mobileNum = n;
    
    for (int i = 0; i < n; ++i) {
        permutation[i].num = i + 1;
        permutation[i].pointsLeft = true;
    }
}
bool PermutationGenerator::next() {
    if (!hasMobile) return false;
    
    ++permCount;
    hasMobile = false;
    
    //move mobile element
    if (permutation[mobileIndex].pointsLeft) {
        permutation[mobileIndex].swapElement(permutation[mobileIndex - 1]);
        if (mobileNum == n) mobileIndex -= 1;
    } else {
        permutation[mobileIndex].swapElement(permutation[mobileIndex + 1]);
        if (mobileNum == n) mobileIndex += 1;
    }
    
    //reverse direction of each element greater than swapped element
    if (mobileNum < n) 
        for (int i = 0, max = n - mobileNum, flipped = 0; flipped < max; ++i) 
            if (permutation[i].num > mobileNum) {
                permutation[i].pointsLeft = !permutation[i].pointsLeft;
                flipped += 1;
            }
            
    //need to search for mobile element
    int last = n - 1;
    if (mobileIndex==0 || mobileIndex==last || mobileNum<n) {
        int maxMobile = 0;
        
        for (int i = 0; i < n; ++i) {
            //largest element moves most consistantly and only need to check direction
            if ( permutation[i].num==n && ((permutation[i].pointsLeft && i>0) || (!permutation[i].pointsLeft && i<last)) ) {
                mobileIndex = i;
                hasMobile = true;
                mobileNum = permutation[i].num;
                break;
            }
            bool test = false;
            //check edges of array differently
            if (i==0 || i==last) {
                //don't need max mobile check if first (always true)
                if (i == 0) {    
                    if (!permutation[0].pointsLeft)    //if first only valid if points right
                        if (permutation[0].num > permutation[1].num) test = true;
                } 
                else if (permutation[last].num > maxMobile) {
                    if (permutation[last].pointsLeft)    //if last only valid if points left
                        if (permutation[last].num > permutation[last - 1].num) test = true;
                }
            } else if (permutation[i].num > maxMobile) {    //only check if number is bigger
                if (!permutation[i].pointsLeft) { //first check right
                    if (permutation[i].num > permutation[i + 1].num) test = true;
                }
                else if (permutation[i].num > permutation[i - 1].num) test = true;    //otherwise left
            }
            if (test) {
                    hasMobile = true;
                    mobileNum = maxMobile = permutation[i].num;
                    mobileIndex = i;
            }
        }
    } 
    else hasMobile = true;    //if not on edge and is largest then mobile
    return hasMobile;
}

