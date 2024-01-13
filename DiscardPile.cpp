/*
CSCI1120 Assignment 6

Name        : LEE Shing Hei
Student ID  : 1155183712
Email       : lshcyrus@link.cuhk.edu.hk
*/

#include <iostream>
#include "DiscardPile.h"

using namespace std;

DiscardPile::DiscardPile() : Deck(false) {
}

Card* DiscardPile::top() const {
    if (cards.size() > 0)
        return cards.back();
    else
        return nullptr;
}

void DiscardPile::stack(Card* card) {
    cards.push_back(card);
}
