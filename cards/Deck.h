#ifndef _DECK_H_
#define _DECK_H_

#include <iostream>

#include "UnorderedList.h"

class Deck : public UnorderedList {
 public:
    Deck() {};
    void GenerateDeck();
    void PrintDeck(std::ostream& out);
    void Shuffle();
};

#endif
