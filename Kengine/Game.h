#pragma once

#include <stack>

#include "SFML/Graphics.hpp"

namespace Kengine
{
	class GameState;

	///////////////////////////////////////////////////////////////////////////
	// 
	//	Game is the primary game class used within Kengine. It handles such
	//	things as the game-window aswell as the gameloop.
	//
	//	Example use:	Kengine::Game game(width, height, fps, fullscreen);	
	//					game.changeState(Kengine::GameState state);
	//					game.gameLoop(); //Starts the gameloop
	// 
	///////////////////////////////////////////////////////////////////////////
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

		void showSystemCursor(bool show);

		Game(int width = 640, int height = 360, int fps = 0, bool fullscreen = true);
		~Game();

	private:
		sf::Event m_event;

		sf::Clock			m_clock;
		sf::Time			m_elapsed;
		
		float				m_dt = 0.0f;
		float				m_accumulator = 0.0f;
		const float			m_timestep = 1.0f / 10.0f;
		const float			m_speed = 60.0f;
	};
}