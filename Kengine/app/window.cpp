#include "window.h"

kengine::Window::Window()
{
	m_width = 640;
	m_height = 400;
	m_title = "Temp";
	sf::Window::create(sf::VideoMode(m_width, m_height), m_title.c_str());
}

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
	while (pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			close();
	}
}