#pragma once

#include <iostream>

#include "GameState.h"

#include "Player.h"

class GameStatePlay : public Kengine::GameState
{
public:
	GameStatePlay(Kengine::Game* game);

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput(sf::Event event);

private:

	sf::View		m_hudView;
	sf::View		m_gameView;

	Player			m_player;

	sf::Texture		m_hudTexture;
	sf::Sprite		m_hudSprite;
	sf::Texture		m_mapTexture;
	sf::Sprite		m_mapSprite;
};