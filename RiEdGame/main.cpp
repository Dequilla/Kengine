#include "Game.h"
#include "GameStateOpeningScreen.h"

int main()
{
	//width, height, fps
	Game game(1360, 768, 60);

	game.pushState(new GameStateOpeningScreen(&game));
	game.gameLoop();

	return 0;
}