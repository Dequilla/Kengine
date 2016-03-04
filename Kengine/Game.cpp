#include <stack>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

#include <iostream>

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

		while (window.isOpen())
		{
			this->m_elapsed = m_clock.getElapsedTime();
			this->m_dt = m_elapsed.asSeconds();
			this->m_clock.restart();
			this->m_fps = (1.0f / this->m_dt);

			//std::cout <<  "FPS: " << m_fps << std::endl;

			if (peekState() == nullptr) continue;
			this->handleEvents(); //Window events and input
			this->update(this->m_dt); //Game updates
			this->draw(this->m_dt); //Handles all the drawing	
			
			
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
				window.setView(sf::View(sf::FloatRect(0.0f, 0.0f, m_event.size.width, m_event.size.height)));
		}
	}

	void Game::showSystemCursor(bool show)
	{
		this->window.setMouseCursorVisible(show);
	}

	void Game::setVerticalSync(bool verticalSync)
	{
		window.setVerticalSyncEnabled(verticalSync);
	}

	Game::Game(int width, int height, int fps, bool fullscreen)
	{
		if (fullscreen == true)
		{
			window.create(sf::VideoMode(width, height), "Kengine", sf::Style::Fullscreen);
		}
		else if (fullscreen == false)
		{
			window.create(sf::VideoMode(width, height), "Kengine", sf::Style::Titlebar | sf::Style::Close);
		}
		
		if (fps > 0)
		{
			window.setFramerateLimit(fps);
		}
		/*else if (fps <= 0)
		{
			//No fps limit
		}*/
	}

	Game::~Game()
	{
	}

}