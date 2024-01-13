/*
CSCI1120 Assignment 6

Name        : LEE Shing Hei
Student ID  : 1155183712
Email       : lshcyrus@link.cuhk.edu.hk
*/

#include <iostream>
#include "Player.h"

using namespace std;

int Player::count = 0; 

Player::Player() {
    count++;
    name = "Player " + to_string(count);
}

string Player::getName() const {
    return name;
}

void Player::setName(string name_) {
    name = name_;
}

int Player::drawCard(DrawPile* drawPile, int n) {
    int d = drawPile->draw(hand, n);
    if (d == 0) {
        cout << "No more cards on draw pile!" << endl;
    }
    else {
        cout << name << " drawn " << d << " card(s)." << endl;
    }
    return d;
}

void Player::printHand(bool flipped) {
    if (flipped == true) {
        for (int i = 0; i < handSize(); i++) {
            cout << hand[i]->toString();
            if (i != handSize() - 1) {
                cout << " ";
            }
        }
    }
    else {
        for (int i = 0; i < handSize(); i++) {
            cout << "[Uno]";
            if (i != handSize() - 1) {
				cout << " ";
			}
        }
    }
    cout << endl;
}

int Player::handSize() const {
    return int(hand.size());
}

int Player::handPoints() const {
    int sum = 0;                                    // declare sum variable to store the total points of the cards in hand
    for (int i = 0; i < handSize(); i++) {
        sum += int(hand[i]->getValue());			// add the value of each card in hand to sum
    }
    return sum;
}

void Player::playCard(int idx, GameState& uno) {
    Card* card = hand.at(idx);
    card->play(uno);

    // Move the card from hand to discard pile
    uno.discardPile->stack(card);
    hand.erase(hand.begin() + idx);
}

Color Player::mostFrequentColor() {

    int red = 0, yellow = 0, green = 0, blue = 0;           // declare variables to store the total number of cards of each color

    for (int i = 0; i < handSize(); i++) {
        if (hand[i]->getColor() == Color::Red) {            // if the card is red
            red++;                                          // add 1 to the total number of red cards
        }
        else if (hand[i]->getColor() == Color::Yellow) {    // if the card is yellow
            yellow++;                                       // add 1 to the total number of yellow cards
        }
        else if (hand[i]->getColor() == Color::Green) {     // if the card is green
            green++;    						            // add 1 to the total number of green cards     
        }
        else if (hand[i]->getColor() == Color::Blue) {      // if the card is blue
            blue++; 									    // add 1 to the total number of blue cards
        }
        else
            continue;
    }

    // Find the most frequent color
    int max = red;                                          // set red as the initial most frequently appeared color

    if (yellow > max) {                                     // compare appearance of yellow with the current max
        max = yellow;									    // set yellow as the new max
    }

    if (green > max) {  							        // compare appearance of green with the current max
        max = green;									    // set green as the new max
    }

    if (blue > max) {       		                        // compare appearance of blue with the current max
        max = blue; 									    // set blue as the new max
    }

    // Return the most frequent color in order of red, yellow, green, blue

    if (max == red) {
        return Color::Red;                                  // return red first if it is the most frequent color among all or equally same as other colors
    }
    else if (max == yellow) {
        return Color::Yellow;                               
    }
    else if (max == green) {
        return Color::Green;
    }
    else {
        return Color::Blue;
    }
}

