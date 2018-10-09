#include <stdlib.h>
#include <assert.h>
#include "Player.h"
#include "Strategy.h"
#include "Game.h"

/*! Tests split functionality: 7,7 v. 7
Hand splits then one busts and the other pushes.
*/
void test0e() {
	srand(1);

	Strategy bs = BasicStrategy_();

	Player player = Player_(&bs);
	init(&player);

	Card card1 = Card_(SEVEN, HEARTS);
	hit(&player.hands[0], &card1);

	Card card2 = Card_(SEVEN, SPADES);
	hit(&player.hands[0], &card2);

	Hand dealer = Hand_();

	// Causes player to not STAY
	Card upcard = Card_(SEVEN, CLUBS);
	hit(&dealer, &upcard);

	play(&player, &upcard);

	assert(player.size == 3);

	Game statistics = Game_();
	play(&dealer, &player, &statistics);

	assert(statistics.count[BUSTS] == 1 && statistics.count[WINS] && statistics.count[PUSHES] == 1);

	statistics.pl = player.pl;
	statistics.nohands = statistics.count[BUSTS] + statistics.count[PUSHES] == 1 + statistics.count[PUSHES];

	output(&statistics, 0);
}