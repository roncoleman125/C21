#include <stdlib.h>
#include <assert.h>
#include "Player.h"
#include "Strategy.h"
#include "Game.h"

/*! Tests split functionality: 6,6 v. 5
Hand splits, both stay.
*/
void test0d() {
	srand(1);

	Strategy bs = BasicStrategy_();

	Player player = Player_(&bs);
	init(&player);

	Card card1 = Card_(SIX, HEARTS);
	hit(&player.hands[0], &card1);

	Card card2 = Card_(SIX, SPADES);
	hit(&player.hands[0], &card2);

	Hand dealer = Hand_();

	// Causes player to STAND
	Card upcard = Card_(FIVE, CLUBS);
	hit(&dealer, &upcard);

	play(&player, &upcard);

	assert(player.size == 2);

	Game statistics = Game_();
	play(&dealer, &player, &statistics);

	assert(statistics.count[LOSSES] == 2);

	statistics.nohands = statistics.count[LOSSES];

	statistics.pl = player.pl;

	output(&statistics, 0);
}