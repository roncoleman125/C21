#include <assert.h>
#include "Hand.h"
#include "Strategy.h"

/* Tests IV: 4,4 v. 4 */
void test03() {
	Hand hand = Hand_();

	Card card1 = Card_(FOUR, DIAMONDS);
	hit(&hand, &card1);

	Card card2 = Card_(FOUR, HEARTS);
	hit(&hand, &card2);

	Card upcard = Card_(FOUR, SPADES);

	Strategy bs = BasicStrategy_();
	Play play = doSection4(&hand, &upcard, &bs);

	assert(play == HIT);
}