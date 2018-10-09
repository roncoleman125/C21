#include "Game.h"
#include "Strategy.h"

/*! Tests 10 games
*/
void test0f() {
	Strategy bs = BasicStrategy_();

	Game statistics = start(&bs, 10, 2);

	output(&statistics, 0);
}