#include "Game.h"

/*! Tests one game
*/
void test0c() {
	Strategy bs = BasicStrategy_();

	Game statistics = start(&bs, 1, 0);

	output(&statistics,0);
}