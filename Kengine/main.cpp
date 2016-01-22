#include "SFML/Graphics.hpp"
#include <iostream>
#include "app/window.h"
#include "graphics/renderer.h"

int main()
{
	
	
	Window window(800, 600, "BAJS");
	Renderer renderer;

	while (window.isOpen())
	{
		
		window.windowEvents();
		window.clear();
		window.display();	

	}

	return 0;
}