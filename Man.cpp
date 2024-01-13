/*
CSCI1120 Assignment 6

Name        : LEE Shing Hei
Student ID  : 1155183712
Email       : lshcyrus@link.cuhk.edu.hk
*/

#include <iostream>
#include <iomanip>
// You may add additional headers if needed
#include <sstream>

#include "Man.h"

using namespace std;

Man::Man() : Player() {
    setName(getName() + " (Man)");
}

int Man::pickCard(GameState& uno) {
    bool matched = false;   // declare boolean variable to check if there is a playable card in hand

    for (int i = 0; i < handSize(); i++) {
        if (hand[i]->match(uno.discardPile->top())) {
			matched = true;
		}
    }
    
    // if no playable card in hand and draw pile is empty, return PASSED
    if (uno.drawPile->size() == 0 && !matched) {    
        cout << "Turn passed!" << endl;
		return PASSED;
	}

    // print player hand
    for (int i = 0; i < handSize(); i++) {
		cout << setw(4) << right << (hand[i]->match(uno.discardPile->top()) ? "[" + to_string(i) + "]" : "[x]") << hand[i]->toString() << " ";
        if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}

    // Show the [D]raw option if draw pile still has cards.
    if (uno.drawPile->size() > 0) {
        cout << " " << "[D]raw" << endl;
    }
    else
        cout << endl;
   
    bool validOption = false;   // declare boolean variable to check if the option entered is valid

    do {
        string optionInput;	  // declare string variable to store the option entered by user
        //cin.clear();                                          
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter option: ";
        cin >> optionInput;

        // if the option entered is a single character between A-Z or a-z
        if (optionInput[0] >= 'A' && optionInput[0] <= 'Z' || optionInput[0] >= 'a' && optionInput[0] <= 'z') {
            // if the option entered is 'D' or 'd'
            if (optionInput == "D" || optionInput == "d") {
                // if draw pile still has cards
                if (uno.drawPile->size() > 0) {
                    validOption = true;                                     // entered option is valid

                    uno.players[*uno.turn]->drawCard(uno.drawPile, 1);      // draw 1 card from draw pile to turn player hand

                    cout << "Drawn " << hand.back()->toString() << endl;    // print the drawn card from turn player hand

                    if (hand.back()->match(uno.discardPile->top())) {	    // if the drawn card is playable
                        return handSize() - 1;                              // return index of the matched drawn card
                    }
                    else {
                        return DRAWN;			                            // return DRAWN if the drawn card is not playable
                    }
                }
                else {
					cout << "Invalid option!" << endl;
				}
            }
            else {
                cout << "Invalid option!" << endl;
            }
        }
        else {

            // boolean checking whether all the characters in optionInput are integers
            bool isInteger = true;

            // check if all the characters in optionInput are integers
            for (int i = 0; i < optionInput.length(); i++) {
                if (optionInput[i] < '0' || optionInput[i] > '9') {
                    cout << "Invalid option!" << endl;
                    isInteger = false;
                    break;
                }
            }

            // if all the characters in optionInput are integers
            if (isInteger) {
                int index;

                // input string stream to read integer index from optionInput
                std::istringstream iss(optionInput);

                // extract values from input string stream into integer index 
                iss >> index;

                // if the index entered is within the range of the player hand size
                if (index >= 0 && index < handSize()) {
                    if (hand[index]->match(uno.discardPile->top())) {
                        validOption = true;
                        return index;
                    }
                    else {
                        cout << "Invalid option!" << endl;
                    }
                }
                else {
                    cout << "Invalid option!" << endl;
                }
            }
        }
    } while (!validOption);
}
