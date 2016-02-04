#include "Game.h"

kengine::Game::Game() : m_gameWindow(sf::RenderWindow(sf::VideoMode(600,400),"TEMP"))
{
	m_gameWindow.create(sf::VideoMode(600, 400), "TEMP");
}

kengine::Game::~Game()
{
	while (!this->m_states.empty()) popState();
}

void kengine::Game::changeState(kengine::GameState* state)
{
	// If the state stack is not empty, empty it and
	// push the selected state to the top of the stack
	if (!this->m_states.empty()) popState();
	pushState(state);
	
	return;
}

void kengine::Game::pushState(kengine::GameState* state)
{
	this->m_states.push(state);

	return;
}

void kengine::Game::popState()
{
	delete this->m_states.top();
	this->m_states.pop();

	return;
}

kengine::GameState* kengine::Game::peekState()
{
	if(this->m_states.empty()) return nullptr;
	return this->m_states.top();
}

void kengine::Game::handleEvents()
{
	while (m_gameWindow.pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			m_gameWindow.close();
	}
}

void kengine::Game::update()
{
}

void kengine::Game::draw()
{
	m_gameWindow.clear();
	peekState()->draw(m_gameWindow);
	m_gameWindow.display();
}

void kengine::Game::gameLoop()
{
	while (this->m_gameWindow.isOpen())
	{
		this->handleEvents();
		this->draw();
	}
}
