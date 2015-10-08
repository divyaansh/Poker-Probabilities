//game1.h

#ifndef _GAME1_H
#define _GAME1_H
#include "card.h"
#include "deck.h"

class Game {

		Game();
		bool isPair(Card *);
		bool isFlush(Card *);

};

#endif