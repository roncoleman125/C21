#include <assert.h>
#include "Hand.h"
#include "Strategy.h"

/* Tests I: 10+3+7 v. 6 */
void test0a() {
	Hand hand = Hand_();

	Card card1 = Card_(TEN, DIAMONDS);
	hit(&hand, &card1);

	Card card2 = Card_(THREE, HEARTS);
	hit(&hand, &card2);

	Card card3 = Card_(SEVEN, CLUBS);
	hit(&hand, &card3);

	Card upcard = Card_(TEN, SPADES);

	Strategy bs = BasicStrategy_();
	Play play = doSection1(&hand, &upcard, &bs);

	assert(play == STAY);
}