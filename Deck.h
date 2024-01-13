/*
CSCI1120 Assignment 6

Name        : LEE Shing Hei
Student ID  : 1155183712
Email       : lshcyrus@link.cuhk.edu.hk
*/

#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Reverse.h"
#include "WildDraw4.h"

using std::vector;

class Deck
{
public:
    Deck(bool fill = false);
    void shuffle();
    void print();
protected:
    vector<Card*> cards;
};

#endif // DECK_H