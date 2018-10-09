#include <assert.h>
#include "Hand.h"
#include "Strategy.h"

/* Tests A,A v. 6 */
void test00() {
	Hand hand = Hand_();

	Card card1 = Card_(ACE, DIAMONDS);
	hit(&hand, &card1);

	Card card2 = Card_(ACE, HEARTS);
	hit(&hand, &card2);

	Card upcard = Card_(SIX, SPADES);

	Strategy bs = BasicStrategy_();
	Play play = doSection4(&hand, &upcard, &bs);

	assert(play == SPLIT);
}