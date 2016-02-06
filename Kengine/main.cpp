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

	//
	// old code below
	//

	//Make the game class make its own window
	/*kengine::Window window(800, 600, "BAJS"); //Try using pointer on window
	kengine::Player player("images/test.png", 1, 1);
	player.setSize(100, 100);*/

	/*while (window.isOpen())
	{
		player.checkInput();
		window.windowEvents();
		window.clear();
		window.draw(player.getPlayerSprite());
		window.display();	

		sf::Time dt = deltaClock.restart();
		std::cout << "DT as MS: " << dt.asMilliseconds() << std::endl;

	}*/

	return 0;
}