#pragma once
#include "../app/GameState.h"
#include "MainMenu.h"


class OpenScreen : public kengine::GameState
{
public:
	OpenScreen(kengine::Game* game);
	~OpenScreen();

	void pause();
	void resume();

	void handleEvents(sf::Time &deltaTime);
	void update();
	void draw(sf::RenderWindow &gameWindow);

private:
	kengine::Game*	m_game;
	//fix this with state manager later
	MainMenu*		m_mainMenu = new MainMenu;
	sf::Texture		m_openingImage;
	sf::Sprite		m_openingSprite;
	sf::Clock		m_clock;
	float			m_elapsedTime = 0, m_opacityChecker = 0.05f;
	int				m_opacity = 0;
	bool			m_fading = false, m_finished = false;
};