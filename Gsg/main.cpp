#define SCREEN_WIDTH 1632
#define SCREEN_HEIGHT 918

#include "game.h"

int main()
{
	Game game(SCREEN_WIDTH, SCREEN_HEIGHT);
	game.run();
	return 0;
}