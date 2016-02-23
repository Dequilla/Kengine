#pragma once

#include <stack>

#include "SFML/Graphics.hpp"

namespace Kengine
{
	class GameState;

	class Game
	{
	public:
		std::stack<GameState*> states;

		sf::RenderWindow window;

		void pushState(GameState* state);
		void popState();
		void changeState(GameState* state);
		GameState* peekState();

		void gameLoop();
		void draw(const float dt);
		void update(const float dt);
		void handleEvents();

		Game(int width = 640, int height = 360, int fps = 60);
		~Game();

	private:
		sf::Event m_event;
	};
}