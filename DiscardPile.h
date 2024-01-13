/*
CSCI1120 Assignment 6

Name        : LEE Shing Hei
Student ID  : 1155183712
Email       : lshcyrus@link.cuhk.edu.hk
*/

#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include "Deck.h"

class DiscardPile : public Deck
{
public:
    DiscardPile();
    Card* top() const;
    void stack(Card* card);
};

#endif // DISCARDPILE_H