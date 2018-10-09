#include <assert.h>
#include "Hand.h"
#include "Strategy.h"

/* Tests I: 10+A v. 10 */
void test09() {
	Hand hand = Hand_();

	Card card1 = Card_(TEN, DIAMONDS);
	hit(&hand, &card1);

	Card card2 = Card_(ACE, HEARTS);
	hit(&hand, &card2);

	Card upcard = Card_(TEN, SPADES);

	Strategy bs = BasicStrategy_();
	Play play = doSection1(&hand, &upcard, &bs);

	assert(play == STAY);
}