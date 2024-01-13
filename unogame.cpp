/*
CSCI1120 Assignment 6

Name        : LEE Shing Hei
Student ID  : 1155183712
Email       : lshcyrus@link.cuhk.edu.hk
*/

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <climits>
// You may add additional headers if needed

#include "ActionCard.h"
#include "Man.h"
#include "Bot.h"
#include "DrawPile.h"
#include "DiscardPile.h"

using namespace std;

int main()
{
	// Get the game start-up parameters 
	string input;
	unsigned int seed = 123;
	cout << "Enter seed (or hit Enter): ";
	getline(cin, input);
	if (!input.empty()) {
		seed = stoi(input);
	}
	cout << "Seed: " << seed << endl;
	srand(seed);

	bool debugMode = false;
	cout << "Play in debug mode (Y/N)? ";
	getline(cin, input);
	if (input == "Y" || input == "y" || input == "") {
		debugMode = true;
	}
	cout << "Debug mode: " << boolalpha << debugMode << endl;

	int turnsMax = 100;
	cout << "Max. turns to play: ";
	getline(cin, input);
	if (!input.empty()) {
		turnsMax = stoi(input);
	}
	cout << "Max. turns: " << turnsMax << endl;

	int M, B, P;
	while (true) {
		cout << "Enter # man and bot players: ";
		cin >> M >> B;
		P = M + B;
		if (P >= 2 && P <= 5)
			break;
		cout << "Require 2 to 5 players!" << endl;
	}
	cout << "#Men: " << M << "; #Bots: " << B << endl;

	// Create an array of pointers to Player objects
	Player** players = new Player * [P];
	for (int i = 0; i < P; i++) {
		if (i < M)
			players[i] = new Man;
		else
			players[i] = new Bot;
	}
	Player* player = players[0];  // current player

	// Define variables to track the game state
	DrawPile drawPile;
	DiscardPile discardPile;
	bool turnSkipped = false;
	int cardsToDraw = 0;
	int delta = 1;
	int turn = 0;

	GameState uno{ players, &drawPile, &discardPile,
		&turnSkipped, &cardsToDraw, &turn, &delta, P, debugMode
	};

	// Shuffle the deck and deal cards to each player
	if (debugMode) {
		cout << "Cards created:" << endl;
		drawPile.print();
	}
	drawPile.shuffle();
	for (int i = 0; i < P; i++) {
		players[i]->drawCard(&drawPile, H);
	}

	// Draw the first card onto discard pile
	vector<Card*> firstCard;
	drawPile.draw(firstCard, 1);
	discardPile.stack(firstCard.at(0));
	if (debugMode) {
		cout << "Draw pile after shuffling and dealing:" << endl;
		drawPile.print();
	}

	// Start the game loop

	int gameRound = 1;	// count the number of turns played
	int passedCnt = 0;	// count the number of players consecutively passed their turns

	while (gameRound <= turnsMax) {

		cout << "=========================================================\n";
		cout << "Turn " << gameRound << ": \n";
		cout << "Discard Pile: " << discardPile.top()->toString() << "  " << "Current Color: " << setw(8) << left << COLORS[int(discardPile.top()->getColor())] << "Draw Pile: " << to_string(drawPile.size()) << endl;
		cout << "---------------------------------------------------------\n";
		
		cout << players[turn]->getName() << ":" << endl;

		if (cardsToDraw > 0) {
			players[turn]->drawCard(&drawPile, cardsToDraw);
			cardsToDraw = 0;
		}

		// if current player is not skipping the turn
		if (!turnSkipped) {
			int pickResult = players[turn]->pickCard(uno);
			if (pickResult != PASSED && pickResult != DRAWN) {
				players[turn]->playCard(pickResult, uno);
			}

			// (2) all players consecutively passed their turns (i.e., no one can play a card or draw).
			if (pickResult == PASSED) {
				passedCnt += 1;
			}
			else {
				passedCnt = 0;
			}

			// if all players passed, game over
			if (passedCnt == P) {
				break;
			}
		}
		else {
			cout << "Turn skipped!" << endl;
			turnSkipped = false;
			turn = (turn + delta + P) % P;
			gameRound++;
			continue;
		}
		
		// Check game over condition. Exit the game loop if either:
		// (1) current player's hand has no cards.
		if (players[turn]->handSize() == 0) {
			break;
		}
		// (3) the maximum turns to play set by the user has been reached.
		// checked at the end of the game loop, if gameRound > turnsMax, game over

		// Update the turn integer to let the next player become current.
		turn = (turn + delta + P) % P;
		gameRound++;
	}
	
	// Game over
	cout << "**********\n";
	cout << "Game Over!\n";
	cout << "**********\n";
	for (int i = 0; i < P; i++) {
		cout << players[i]->getName() << " owes " << setw(4) << right << players[i]->handPoints() << " point(s): "; players[i]->printHand(true);
	}

	// decide winner
	int min = 0;
	bool winnerFound = false;

	for (int i = 0; i < P; i++) {
		if (players[i]->handSize() == 0) {
			cout << "The winner is " << players[i]->getName() << "!";
			winnerFound = true;
			break;
		}
		
	}

	if (!winnerFound) {
		for (int i = 0; i < P; i++) {
			if (players[i]->handPoints() < players[min]->handPoints()) {
				min = i;
			}
		}
		cout << "The winner is " << players[min]->getName() << "!";
	}
	
}