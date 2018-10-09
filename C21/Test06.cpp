#include <assert.h>
#include "Hand.h"
#include "Strategy.h"

/* Tests III: A,2 v. A */
void test06() {
	Hand hand = Hand_();

	Card card1 = Card_(TWO, DIAMONDS);
	hit(&hand, &card1);

	Card card2 = Card_(ACE, HEARTS);
	hit(&hand, &card2);

	Card upcard = Card_(ACE, SPADES);

	Strategy bs = BasicStrategy_();
	Play play = doSection3(&hand, &upcard, &bs);

	assert(play == HIT);
}