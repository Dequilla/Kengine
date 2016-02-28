#pragma once

#include "Game.h"

namespace Kengine
{
	///////////////////////////////////////////////////////////////////////////
	// 
	//	Kengine::GameState is the abstract class on which you build your
	//	own gamestates used with the Kengine engine.
	// 
	///////////////////////////////////////////////////////////////////////////
	class GameState
	{
	public:
		Game* m_game;

		virtual void draw(const float dt) = 0;
		virtual void update(const float dt) = 0;
		virtual void handleInput(sf::Event event) = 0;
	};
}