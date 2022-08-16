
#include <iostream>

#include <cstdlib>
#include <ctime>

#include "Card.h"

#include "Deck.h"

void Deck::GenerateDeck() {
    MakeEmpty();
    for (Suits suit = CLUBS; suit <= SPADES; suit = Suits(suit + 1)) {
        for (int rank = 1; rank <= 13; rank++) {
            PutItem(Card(rank, suit));
        }
    }
}

void Deck::PrintDeck(std::ostream& out) {
    ItemType card;
    while (HasNext()) {
        card = GetNext();
        card.print(out);
        out << std::endl;
    }
}

void Deck::Shuffle() {
    if (GetLength() != 52) {
        throw "Can't shuffle without 52 cards";
    }
    Deck left;
    Deck right;
    std::srand(std::time(0));
    int p = 23 + (std::rand() % 8);
    reset();
    for (int i = 0; i < 52; i++) {
        Card card = GetNext();
        if (i < p) {
            left.PutItem(card);
        } else {
            right.PutItem(card);
        }
    }
    MakeEmpty();
    while (left.HasNext() || right.HasNext()) {
        if (left.HasNext()) {
            PutItem(left.GetNext());
        }
        if (right.HasNext()) {
            PutItem(right.GetNext());
        }
    }
}
