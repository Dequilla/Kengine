#include "Game.h"
#include "GameStateOpeningScreen.h"
#include "Kopter.h"

int main()
{

	//	Our own options file reader(will also parse in the future)
	Kengine::Kopter	options;

	int fps = 0;
	int width = 1360;
	int height = 768;
	bool fullscreen = false;

	//	If the options-file is successfully read
	//	Set values read from said file
	if (options.readFile("options.kopt"))
	{
		fps = options.getIntOptionAt("fps");
		width = options.getIntOptionAt("gamewidth");
		height = options.getIntOptionAt("gameheight");
		fullscreen = options.getBoolOptionAt("fullscreen");
	}

	Kengine::Game game(width, height, fps, fullscreen);
	
	game.showSystemCursor(true);

	game.pushState(new GameStateOpeningScreen(&game));
	game.gameLoop();

	return 0;
}