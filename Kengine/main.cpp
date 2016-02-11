#include "SFML/Graphics.hpp"
#include <iostream>
#include "app/Window.h"
#include "player/Player.h"
#include "app/Game.h"
#include "app/GameState.h"
#include "gameStates/OpenScreen.h"

int main()
{

	//TODO
	//Make state manage, std::map<string mapName, kengine::GameState>
	//Make managgers for everything that doesnt have it so we can implement load functions

	kengine::Game game;

	OpenScreen state(&game);
	game.pushState(&state);

	game.gameLoop();

	return 0;
}