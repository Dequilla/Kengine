#include "SFML/Graphics.hpp"
#include <iostream>
#include "app/Window.h"
#include "player/Player.h"
#include "app/Game.h"
#include "app/GameState.h"
#include "gameStates/testState.h"

int main()
{
	kengine::Game game;

	testState state;
	game.pushState(&state);

	game.gameLoop();

	return 0;
}