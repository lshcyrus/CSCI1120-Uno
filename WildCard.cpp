/*
CSCI1120 Assignment 6

Name        : LEE Shing Hei
Student ID  : 1155183712
Email       : lshcyrus@link.cuhk.edu.hk
*/

#include <iostream>
#include "cctype"
#include "WildCard.h"
#include "WildDraw4.h"
#include "Bot.h"

using namespace std;

WildCard::WildCard() : ActionCard(Color::Wild, Action::ChgColor) {
    setValue(Value::W);
}

bool WildCard::match(Card* /*top*/) {
    // if this color matches wild
    if (this->getColor() == Color::Wild) {
        return true;
    }
    return false;
}

void WildCard::play(GameState& uno) {
    // Check if the "this" pointer is aiming at a WildDraw4 object.
    // If not, call the superclass Card's play() function.
    if (!(dynamic_cast<WildDraw4*>(this))) {
		Card::play(uno);
	}

    Color color;            // declare variable to store the color chosen by the player or bot
    char input; 	        // declare variable to store the input of the player
    bool valid = false;     // declare a boolean variable to check if the input is valid and exit the loop

    if (dynamic_cast<Bot*>(uno.players[*uno.turn])) {
        color = uno.players[*uno.turn]->mostFrequentColor();
        this->setColor(color);
    }
    else {
        do {
            cout << "Choose a color [R, Y, G, B]: ";
            cin >> input;
            input = toupper(input);

            switch (input) {
                case 'R':
					color = Color::Red;
					valid = true;
					break;
                case 'Y':
                    color = Color::Yellow;
                    valid = true;
                    break;
                case 'G':
					color = Color::Green;
					valid = true;
					break;
                case 'B':
                    color = Color::Blue;
                    valid = true;
                    break;
                default: 
                    cout << "Invalid option!" << endl;
					break;
            }

        } while (!valid);

        this->setColor(color);
    }
    // print the changed color chosen by the player or bot
    cout << "Color changed to " << COLORS[int(getColor())] << "!" << endl;
}

string WildCard::toString() {
    return string() + "[" + COLORS[4][0] + ACTIONS[int(getAction())][0] + "]";
}