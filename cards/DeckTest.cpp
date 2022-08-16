
#include <iostream>

#include "Deck.h"

#include "Card.h"

using namespace std;

int main() {
    cout << "About to construct a new empty deck:" << endl;
    Deck d;
    cout << "The initial deck has length:" << endl;
    cout << d.GetLength() << endl;
    cout << "About to Generate the deck of cards..." << endl;
    d.GenerateDeck();
    cout << "The newly-generated deck has length: " << d.GetLength() << endl;
    cout << "About to print the deck..." << endl;
    d.PrintDeck(cout);
    cout << endl << "That is all..." << endl;
    cout << "ABout to shuffle the deck!" << endl;
    d.Shuffle();
    cout << "After shuffling, the deck looks like:" << endl;
    d.PrintDeck(cout);
    cout << "That is all." << endl;
}
