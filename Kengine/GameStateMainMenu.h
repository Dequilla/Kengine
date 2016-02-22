#pragma once

#include "GameState.h"
#include "MenuButton.h"
#include "GameStateOpeningScreen.h"

#include <iostream>

class GameStateMainMenu : public GameState
{
public:
	GameStateMainMenu(Game* game);

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput(sf::Event event);

private:

	sf::Font		temp_font;
	MenuButton		m_buttonExitGame, m_buttonStartGame;
	sf::Text		m_textMenu;
	sf::Texture		m_textureBackground;
	sf::Sprite		m_spriteBackground;

};