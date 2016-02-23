#pragma once

#include "Game.h"

namespace Kengine
{
	class GameState
	{
	public:
		Game* m_game;

		virtual void draw(const float dt) = 0;
		virtual void update(const float dt) = 0;
		virtual void handleInput(sf::Event event) = 0;
	};
}