#pragma once
#include "../app/GameState.h"
#include "../player/Player.h"

class GameState;

class testState : public kengine::GameState
{

	public:
		testState();
		~testState();

		void pause();
		void resume();

		void handleEvents();
		void update();
		void draw(sf::RenderWindow &gameWindow);

		bool running() { return m_running; }
		void quit() { m_running = false; }


	private:
		bool m_running;
		kengine::Player *m_player = nullptr;

};