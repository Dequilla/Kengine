#pragma once
#include "Game.h"
#include "window.h"

namespace kengine
{
	class Game;

	class GameState
	{
	public:
		
		GameState() {};
		~GameState() {};

		virtual void pause() = 0;
		virtual void resume() = 0;

		virtual void handleEvents(sf::Time &deltaTime) = 0;
		virtual void update() = 0;
		virtual void draw(sf::RenderWindow &gameWindow) = 0;

		void changeState(Game* game, GameState* state);

		bool running() { return m_running; }
		void quit() { m_running = false; }

	private:
		bool m_running;

	};
}