/*
CSCI1120 Assignment 6

Name        : LEE Shing Hei
Student ID  : 1155183712
Email       : lshcyrus@link.cuhk.edu.hk
*/

#ifndef BOT_H
#define BOT_H

#include "Player.h"

class Bot : public Player
{
public:
	Bot();
	virtual int pickCard(GameState& uno) override;
};

#endif // BOT_H