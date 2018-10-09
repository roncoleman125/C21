#include <assert.h>
#include "Hand.h"
#include "Strategy.h"

/* Tests I: 3+3+7 v. 8 */
void test0b() {
	Hand hand = Hand_();

	Card card1 = Card_(SEVEN, DIAMONDS);
	hit(&hand, &card1);

	Card card2 = Card_(THREE, HEARTS);
	hit(&hand, &card2);

	Card card3 = Card_(THREE, CLUBS);
	hit(&hand, &card3);

	Card upcard = Card_(EIGHT, SPADES);

	Strategy bs = BasicStrategy_();
	Play play = doSection1(&hand, &upcard, &bs);

	assert(play == HIT);
}