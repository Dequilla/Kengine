#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

namespace kengine 
{
	
	class Window : public sf::RenderWindow
	{

	public:
		Window();
		Window(int width, int height, std::string title);
		~Window();

		void windowEvents();

	private:
		int m_width, m_height;
		std::string m_title;
		sf::RenderWindow m_window;
		sf::Event m_event;

	};

}