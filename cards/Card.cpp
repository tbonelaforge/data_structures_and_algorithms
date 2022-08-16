
#include "Card.h"

#include <iostream>
#include <string>

Card::Card(int rank, Suits suit) : suit(suit) {
    if (rank < 1 || rank > 13) {
        throw "rank of " + std::to_string(rank) + " not allowed";
    }
    this->rank = rank;
}

Card::Card() {
    rank = 1;
    suit = CLUBS;
}

int Card::getRank() {
    return rank;
}

Suits Card::getSuit() {
    return suit;
}

void Card::print(std::ostream& out) {
    printRank(out);
    out << " of ";
    switch (suit) {
    case CLUBS:
        out << "clubs";
        break;
    case DIAMONDS:
        out << "diamonds";
        break;
    case HEARTS:
        out << "hearts";
        break;
    case SPADES:
        out << "spades";
        break;
    default:
        out << "unknown";
        break;        
    }
}

void Card::printRank(std::ostream& out) {
    if ((rank >= 2) && (rank <= 10)) {
        out << rank;
        return;
    }
    switch (rank) {
    case 1:
        out << "ace";
        break;
    case 11:
        out << "jack";
        break;
    case 12:
        out << "queen";
        break;
    case 13:
        out << "king";
        break;
    default:
        out << "unknown";
        break;
    }
}

RelationType Card::compareTo(Card other) {
    if (suit < other.suit) {
        return LESS;
    }
    if (suit > other.suit) {
        return GREATER;
    }
    if (rank == other.rank) {
        return EQUAL;
    }
    if (rank == 1) {
        return GREATER;
    }
    if (other.rank == 1) {
        return LESS;
    }
    return (rank < other.rank) ? LESS : GREATER;
}
