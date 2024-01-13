/*
CSCI1120 Assignment 6

Name        : LEE Shing Hei
Student ID  : 1155183712
Email       : lshcyrus@link.cuhk.edu.hk
*/

#include <iostream>
#include "ActionCard.h"

using namespace std;

ActionCard::ActionCard(Color c, Action a) : Card(c, Value::A), action(a) {
}

Action ActionCard::getAction() const {
    return action;
}

void ActionCard::setAction(Action a) {
    action = a;
}

bool ActionCard::match(Card* top) {
    bool colorMatch = false, actionMatch = false;

    if (this->getColor() == top->getColor()) {
		colorMatch = true;
	}

    // if top is pointing to an ActionCard object, return new valid pointer, else return null pointer
    ActionCard* newTopPtr = dynamic_cast<ActionCard*>(top);

    if (newTopPtr != NULL) {
        if (this->getAction() == newTopPtr->getAction()) {
            actionMatch = true;
        }
    }

    // Return true if either color or action matches.
    return colorMatch or actionMatch;
}

string ActionCard::toString() {
    return string() + "[" + COLORS[int(getColor())][0] + ACTIONS[int(getAction())][0] + "]";
}