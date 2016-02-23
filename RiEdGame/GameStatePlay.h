#pragma once

#include <iostream>

#include "GameState.h"

class GameStatePlay : public GameState
{
public:
	GameStatePlay(Game* game);

	virtual void draw(float dt);
	virtual void update(float dt);
	virtual void handleInput(sf::Event event);

private:

	sf::View m_hudView, m_gameView;
};