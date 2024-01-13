/*
CSCI1120 Assignment 6

Name        : LEE Shing Hei
Student ID  : 1155183712
Email       : lshcyrus@link.cuhk.edu.hk
*/

#include <iostream>
#include "Skip.h"

using namespace std;

Skip::Skip(Color c) : ActionCard(c, Action::Skip) {
}

void Skip::play(GameState& uno) {
    Card::play(uno);
    *(uno.turnSkipped) = true;
}