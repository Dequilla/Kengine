#include "SFML/Graphics.hpp"
#include <iostream>
#include "app/window.h"
#include "player/Player.h"

int main()
{
	
	
	Window window(800, 600, "BAJS");
	Player player("images/test.png", 1, 1);

	

	while (window.isOpen())
	{
		player.checkInput();
		window.windowEvents();
		window.clear();
		window.draw(player.getPlayerSprite());
		window.display();	

		std::cout << player.getSize().x << " " << player.getSize().y << std::endl;

	}

	return 0;
}