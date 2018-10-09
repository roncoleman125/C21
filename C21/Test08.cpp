#include <assert.h>
#include "Hand.h"
#include "Strategy.h"

/* Tests II: 3+2 v. 6 */
void test08() {
	Hand hand = Hand_();

	Card card1 = Card_(THREE, DIAMONDS);
	hit(&hand, &card1);

	Card card2 = Card_(TWO, HEARTS);
	hit(&hand, &card2);

	Card upcard = Card_(SIX, SPADES);

	Strategy bs = BasicStrategy_();
	Play play = doSection2(&hand, &upcard, &bs);

	assert(play == HIT);
}