/*
CSCI1120 Assignment 6

Name        : LEE Shing Hei
Student ID  : 1155183712
Email       : lshcyrus@link.cuhk.edu.hk
*/

#ifndef DRAWPILE_H
#define DRAWPILE_H

#include "Deck.h"

class DrawPile : public Deck
{
public:
    DrawPile();
    int size() const;
    int draw(vector<Card*> &hand, int n = 1);
};

#endif // DRAWPILE_H