#pragma once

#include "GameState.h"
#include "MenuButton.h"
#include "Button.h"
#include "GameStateOpeningScreen.h"
#include "GameStatePlay.h"

#include <iostream>

class GameStateMainMenu : public Kengine::GameState
{

public:
	GameStateMainMenu(Kengine::Game* game);

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput(sf::Event event);

	void startGame();

private:

	sf::Font			temp_font;
	sf::Text			m_textMenu;
	sf::Texture			m_textureBackground;
	sf::Sprite			m_spriteBackground;

	Kengine::Button		m_buttonExitGame;
	Kengine::Button		m_buttonStartGame;

};