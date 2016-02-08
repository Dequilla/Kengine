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

		sf::Clock getClock();
		sf::Time getDeltaTime();

	private:
		sf::RenderWindow *m_gameWindow = new sf::RenderWindow;
		sf::Clock *m_gameClock = new sf::Clock;
		sf::Time *m_deltaTime = new sf::Time;
		std::stack<GameState*> m_states;
		bool m_running = true;
		sf::Event m_event;
	};

}