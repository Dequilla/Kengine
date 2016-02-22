#pragma once

#include "GameState.h"
#include "GameStateMainMenu.h"

class GameStateOpeningScreen : public GameState
{
public:
	GameStateOpeningScreen(Game* game);

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput(sf::Event event);

private:
	sf::View		m_view;
	sf::Texture		m_openingImage;
	sf::Sprite		m_openingSprite;
	sf::Clock		m_clock;
	float			m_elapsedTime = 0, m_opacityChecker = 0.05f;
	int				m_opacity = 0;
	bool			m_fading = false, m_finished = false;

	void loadMenu();
};