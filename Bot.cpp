/*
CSCI1120 Assignment 6

Name        : LEE Shing Hei
Student ID  : 1155183712
Email       : lshcyrus@link.cuhk.edu.hk
*/

#include <iostream>
#include <iomanip>

#include "Bot.h"

using namespace std;

Bot::Bot() : Player() {
	setName(getName() + " (Bot)");
}

int Bot::pickCard(GameState& uno) {

	// print hand
	if (uno.debugMode == false) {
		printHand(false);	// not flipped
	}
	else {
		printHand(true);	// flipped
	}

	// find playable card
	for (int i = 0; i < handSize(); i++) {
		if (hand[i]->match(uno.discardPile->top())) {
			return i;		// return the index once matches, return to caller and skip remaining part of the file
		}
	}

	// draw a card if no playable card
	int index = 0;
	if (uno.drawPile->size() > 0) {
		drawCard(uno.drawPile, 1);
		index = handSize() - 1;

		if (uno.debugMode == true) {
			cout << "Drawn " << hand[index]->toString() << endl;
		}

		if (hand[index]->match(uno.discardPile->top())) {
			return index;
		}
		else {
			return DRAWN;
		}
	}
	else {
		cout << "Turn passed!" << endl;
		return PASSED;
	}
}