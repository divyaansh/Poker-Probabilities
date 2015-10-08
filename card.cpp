// card.cpp

#include <iostream>
#include "card.h"
using namespace std;

const char * Card::snames[4] = {" Diamonds", "Hearts", "Clubs", "Spades" };
const char * Card::vnames[14] = {" Bad Card", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };

Card::Card() {
	v = NullCard;
}

Card::Card(Suit newSuit, Value newValue) {
	s = newSuit;
	v = newValue;
}

Card::Suit Card::getSuit() {
	return s;
}

Card::Value Card::getValue() {
	return v;
}

void Card::printSuit() {
	cout << snames[s];
}

void Card::printValue() {
	cout << vnames[v];
}

void Card::printCard() {
	printValue();
	cout << " of ";
	printSuit();
}

Card::Suit nextSuit(Card::Suit s) {
	return(s+1 > Card::Spades) ? Card::Diamonds : (Card::Suit) (s+1);
}

Card::Value nextValue(Card::Value v) {
	return(v+1 > Card::King) ? Card::Ace : (Card::Value) (v+1);
}