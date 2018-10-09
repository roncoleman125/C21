#include <assert.h>
#include "Hand.h"
#include "Strategy.h"

/* Tests II: 6+5 v. 7 */
void test07() {
	Hand hand = Hand_();

	Card card1 = Card_(SIX, DIAMONDS);
	hit(&hand, &card1);

	Card card2 = Card_(FIVE, HEARTS);
	hit(&hand, &card2);

	Card upcard = Card_(SEVEN, SPADES);

	Strategy bs = BasicStrategy_();
	Play play = doSection2(&hand, &upcard, &bs);

	assert(play == DOUBLE_DOWN);
}