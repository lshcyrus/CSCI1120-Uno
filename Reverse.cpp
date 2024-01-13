/*
CSCI1120 Assignment 6

Name        : LEE Shing Hei
Student ID  : 1155183712
Email       : lshcyrus@link.cuhk.edu.hk
*/

#include <iostream>
#include "Reverse.h"
using namespace std;

// constructor of Reverse class inherited from ActionCard class
Reverse::Reverse(Color c) : ActionCard(c, Action::Reverse) {
}

void Reverse::play(GameState &uno) {
	Card::play(uno);				// play function from Card class
	*(uno.delta) *= -1;				// reverse the direction of the game
	if (uno.P == 2) {				// if there are only 2 players
		*(uno.turnSkipped) = true;	// skip the next player
	}
}