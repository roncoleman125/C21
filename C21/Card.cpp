/*
Copyright (c) Ron Coleman
Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <assert.h>
#include "Card.h"
#include "Utils.h"

Card Card_(Rank rank, Suit suit) {
	Card card = { rank, suit };
	return card;
}

Card deal() {
	// Get a random suit
	Suit suit = randomSuit();

	// Get a rank
	Rank rank = randomRank();

	// Make a card
	Card card = Card_(rank, suit);
	return card;
}

bool isFace(Card* card) {
	return card->rank == JACK || card->rank == QUEEN || card->rank == KING;
}

bool isAce(Card* card) {
	return card->rank == ACE;
}

bool is10(Card* card) {
	return isFace(card) || card->rank == TEN;
}

Suit randomSuit() {
	Suit suits[] = { HEARTS, SPADES, DIAMONDS, CLUBS };

	int index = random(0, 3);

	return suits[index];
}

Rank randomRank() {
	// Rank ranks[] = { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

	Rank rank = (Rank) random(ACE, KING);
	
	assert(rank >= ACE && rank <= KING);

	//return (Rank) random(ACE, KING);
	return rank;
}