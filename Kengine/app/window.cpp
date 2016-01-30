#include "window.h"

kengine::Window::Window(int width, int height, std::string title)
{
	m_width = width;
	m_height = height;
	m_title = title;
	sf::Window::create(sf::VideoMode(m_width, m_height), m_title.c_str());
}

kengine::Window::~Window()
{
	sf::Window::close();
}

void kengine::Window::windowEvents()
{
	sf::Event event;
	while (this->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->close();
	}
}