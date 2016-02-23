#include <stack>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

#include "Game.h"
#include "GameState.h"
namespace Kengine
{

	void Game::pushState(GameState* state)
	{
		states.push(state);
	}

	void Game::popState()
	{
		states.pop();
	}

	void Game::changeState(GameState* state)
	{
		if (!states.empty()) popState();
		pushState(state);
	}

	GameState* Game::peekState()
	{
		if (states.empty()) return nullptr;
		return states.top();
	}

	void Game::gameLoop()
	{
		sf::Clock clock;

		while (window.isOpen())
		{
			sf::Time elapsed = clock.restart();
			float dt = elapsed.asSeconds();

			if (peekState() == nullptr) continue;
			this->handleEvents(); //Input and window events
			this->update(dt); //Game updates
			this->draw(dt); //Handles all the drawing
		}
	}

	void Game::draw(const float dt)
	{
		this->window.clear(sf::Color::Black);
		this->peekState()->draw(dt);
		this->window.display();
	}

	void Game::update(const float dt)
	{
		this->peekState()->update(dt);
	}

	void Game::handleEvents()
	{
		while (this->window.pollEvent(m_event))
		{
			this->peekState()->handleInput(m_event); //Do state input first

			if (m_event.type == sf::Event::Closed)
				this->window.close();
			if (m_event.type == sf::Event::Resized)
				window.setView(sf::View(sf::FloatRect(0, 0, m_event.size.width, m_event.size.height)));
		}
	}

	Game::Game(int width, int height, int fps)
	{
		window.create(sf::VideoMode(width, height), "Kengine", sf::Style::Titlebar | sf::Style::Close);
		window.setFramerateLimit(fps);
	}

	Game::~Game()
	{
	}

}