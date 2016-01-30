#include "SFML/Graphics.hpp"
#include <iostream>
#include "app/window.h"
#include "player/Player.h"

int main()
{
	
	kengine::Window window(800, 600, "BAJS");
	kengine::Player player("images/test.png", 1, 1);
	player.setSize(100, 100);

	sf::Clock deltaClock;

	while (window.isOpen())
	{
		player.checkInput();
		window.windowEvents();
		window.clear();
		window.draw(player.getPlayerSprite());
		window.display();	

		sf::Time dt = deltaClock.restart();

		std::cout << "DT as MS: " << dt.asMilliseconds() << std::endl;

	}

	return 0;
}