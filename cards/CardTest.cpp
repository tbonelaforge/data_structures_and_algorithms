
#include <iostream>

#include "Card.h"


using namespace std;

void printComparison(RelationType comparison) {
    if (comparison == LESS) {
        cout << "LESS";
    } else if (comparison == GREATER) {
        cout << "GREATER";
    } else if (comparison == EQUAL) {
        cout << "EQUAL";
    } else {
        cout << "UNKNOWN";
    }
}

int main() {
    cout << "About to use the 2-argument constructor..." << endl;
    Card card(2, HEARTS);
    cout << "Just created the ";
    card.print(cout);
    cout << "About to use the no-argument constructor..." << endl;
    Card defaultCard;
    cout << "Just created the ";
    defaultCard.print(cout);
    cout << "About to compare the first to the second..." << endl;
    RelationType comparison = card.compareTo(defaultCard);
    printComparison(comparison);
    cout << endl;
    cout << "About to try a bad constructor..." << endl;
    try {
        Card badCard(-1, CLUBS);
    } catch (string e) {
        cout << "Caught exception: " << endl << e << endl;
    }
    cout << "About to compare the 2 of hearts to the ace of hearts" << endl;
    Card t1(2, HEARTS);
    Card t2(1, HEARTS);
    printComparison(t1.compareTo(t2));
    cout << "About to compare the 4 of diamonds to the 3 of diamonds" << endl;
    Card t3(3, DIAMONDS);
    Card t4(4, DIAMONDS);
    printComparison(t4.compareTo(t3));
}
