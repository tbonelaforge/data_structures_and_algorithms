
#ifndef _CARD_H_
#define _CARD_H_

#include <iostream>

enum Suits { CLUBS, DIAMONDS, HEARTS, SPADES };
enum RelationType { LESS, EQUAL, GREATER };


class Card {
 public:
    Card();
    Card(int rank, Suits suit);
    int getRank();
    Suits getSuit();
    RelationType compareTo(Card other);
    void print(std::ostream& out);
    void printRank(std::ostream& out);
 private:
    int rank;
    Suits suit;
};

typedef Card ItemType;

#endif
