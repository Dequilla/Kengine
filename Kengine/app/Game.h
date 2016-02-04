#pragma once
#include <stack>
#include "GameState.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

namespace kengine
{

	class GameState;

	class Game 
	{
	public:
		Game();
		~Game();
		
		void changeState(GameState* state);
		void pushState(GameState* state);
		void popState();
		GameState* peekState();

		void handleEvents();
		void update();
		void draw();

		bool running() { return m_running; }
		void quit() { m_running = false; }

		void gameLoop();

	private:
		std::stack<GameState*> m_states;
		bool m_running = true;
		sf::RenderWindow &m_gameWindow;
		sf::Event m_event;
	};

}