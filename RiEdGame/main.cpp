#include "Game.h"
#include "GameStateOpeningScreen.h"

#include "INIReader.h"
#include "ini.h"

int main()
{

	INIReader reader("config.ini");

	if (reader.ParseError() < 0)
	{
		std::cout << "Can't load config.ini" << std::endl;
		//Use default settings
	}

	bool fullscreen = false;

	if (reader.Get("options", "fullscreen", "true") == "true")
	{
		fullscreen = true;
	}
	else
	{
		fullscreen = false;
	}

	//TODO write own frame limiter use "0" in meantime
	//width, height, fps
	Kengine::Game game(1360, 768, 0, fullscreen);
	
	game.showSystemCursor(true);

	game.pushState(new GameStateOpeningScreen(&game));
	game.gameLoop();

	return 0;
}