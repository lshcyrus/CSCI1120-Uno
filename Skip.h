/*
CSCI1120 Assignment 6

Name        : LEE Shing Hei
Student ID  : 1155183712
Email       : lshcyrus@link.cuhk.edu.hk
*/

#ifndef SKIP_H
#define SKIP_H

#include "ActionCard.h"

class Skip : public virtual ActionCard {
public:
    Skip(Color c);
    virtual void play(GameState& uno) override;
};

#endif // SKIP_H