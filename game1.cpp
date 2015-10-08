//game1.cpp

#include <stdlib.h>
#include <time.h>
#include "game1.h"
using namespace std;

int main()  {
	srand((unsigned)time(NULL));
	Game game1;
	return 0;
}

Game::Game() {
	float totalPercentPair = 0, totalPercentFlush = 0;
	int i;
	cout << "Trial\tHands\tPairs\tFlushes\t%Pairs\t%Flushes" << endl;
	for(i = 0; i < 10; i++) {
		Deck gameDeck;
		int pairCount = 0, flushCount = 0;
		int j;
		//1000 iterations because in each iteration we are dealing the cards 10 times
		for(j = 1; j <= 1000; j++) {
			int k;
			for(k = 0; k < 50; k += 5) {
				Card hand[5];
				int l;
				for(l = 0; l < 5; l++)
					hand[l] = gameDeck.getCard();
				if(isPair(hand)) pairCount++;
				if(isFlush(hand)) flushCount++;
			}
			gameDeck.Deck::shuffle(100);
		}
		cout << i << "\t10000\t" << pairCount << "\t" << flushCount << "\t" << pairCount / 100.0 << "\t" << flushCount / 100.0 << endl;
		totalPercentPair += (pairCount / 100.0);
		totalPercentFlush += (flushCount / 100.0);
	}
	cout << "Average Percentage of Pairs is " << totalPercentPair / 10 << endl;
	cout << "Average Percentage of Flushes is " << totalPercentFlush / 10;	
}

bool isPair(Card hand[5]) {
	int i;
	bool counted[13] = {false; false; false; false; false; false; false; false; false; false; false; false; false};
	for(i = 0; i < 5; i++) 
		if(counted[hand[i].Card::getValue()]) return true;
		else counted[hand[i].Card::getValue()] = true;
	return false;
}

bool isFlush(Card *) {
	int i;
	Card::Suit currentSuit = hand[0].Card::getSuit();
	for(i = 1; i < 5; i++)
		if(hand[i].Card::getSuit() != currentSuit) return false;
	return true;
}



