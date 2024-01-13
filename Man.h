/*
CSCI1120 Assignment 6

Name        : LEE Shing Hei
Student ID  : 1155183712
Email       : lshcyrus@link.cuhk.edu.hk
*/

#ifndef MAN_H
#define MAN_H

#include "Player.h"

class Man : public Player
{
public:
    Man();
    virtual int pickCard(GameState& uno) override;
};

#endif // MAN_H