// card.h

#ifndef _CARD_H
#define _CARD_H

class Card {

	public:
		// Define types for the suit and value
		enum Suit { Diamonds, Hearts, Clubs, Spades };
		enum Value { NullCard, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack,	Queen, King };
		
	private:
		static const char *snames[4];
		static const char *vnames[14];
		Suit s;
		Value v;
		
	public:
		// Constructors initialize a card
		Card();
		Card(Suit newSuit, Value newValue);
		Suit getSuit(); // Returns a card's suit.
		Value getValue(); // Returns a card's value.
		void printSuit(); // Print a card's suit.
		void printValue(); // Print a card's value.
		void printCard(); // Print a card's suit and value.

};

// Return the next suit or card value in succession
Card::Suit nextSuit(Card::Suit);
Card::Value nextValue(Card::Value);

#endif