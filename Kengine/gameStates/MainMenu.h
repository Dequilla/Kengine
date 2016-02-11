#pragma once
#include "../app/GameState.h"

class MainMenu : public kengine::GameState
{
public:
	MainMenu();
	MainMenu(kengine::Game* game);
	~MainMenu();
	
	void pause();
	void resume();

	void handleEvents(sf::Time &deltaTime);
	void update();
	void draw(sf::RenderWindow &gameWindow);

private:
	kengine::Game*	m_game;
	sf::Font		m_fontNoRain;
	sf::Text		m_mainMenu, m_start, m_exit;

};