#include "GameStateMainMenu.h"

GameStateMainMenu::GameStateMainMenu(Kengine::Game * game)
{
	this->m_game = game;

	if(!this->m_textureBackground.loadFromFile("resources/images/background.png"));
	this->m_spriteBackground.setTexture(m_textureBackground);

	if (!temp_font.loadFromFile("resources/fonts/AYearWithoutRain.ttf")) std::cout << "ERROR: Font not loaded.";

	this->m_textMenu.setFont(this->temp_font);
	this->m_textMenu.setCharacterSize(50);
	this->m_textMenu.setColor(sf::Color::White);
	this->m_textMenu.setString("MAIN MENU!");
	this->m_textMenu.setPosition(sf::Vector2f(300, 100));

	this->m_buttonStartGame.setFont(this->temp_font);
	this->m_buttonStartGame.setCharacterSize(30);
	this->m_buttonStartGame.setColor(sf::Color::White);
	this->m_buttonStartGame.setString("Start game");
	this->m_buttonStartGame.setPosition(sf::Vector2f(300, 200));

	
	this->m_buttonExitGame.setFont(this->temp_font);
	this->m_buttonExitGame.setCharacterSize(30);
	this->m_buttonExitGame.setColor(sf::Color::White);
	this->m_buttonExitGame.setString("Exit game");
	this->m_buttonExitGame.setPosition(sf::Vector2f(300, 250));
}

void GameStateMainMenu::draw(const float dt)
{
	//Always draw background first
	this->m_game->window.draw(this->m_spriteBackground);

	this->m_game->window.draw(this->m_buttonStartGame);
	this->m_game->window.draw(this->m_textMenu);
	this->m_game->window.draw(this->m_buttonExitGame);
}

void GameStateMainMenu::update(const float dt)
{
}

void GameStateMainMenu::handleInput(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Up) std::cout << "UP";
		else if (event.key.code == sf::Keyboard::Down) /*Do something else */;
		if (event.key.code == sf::Keyboard::Left) /*Do something*/;
		else if (event.key.code == sf::Keyboard::Right) /*Do something*/;
		break;
	case sf::Event::MouseButtonPressed:
		if (this->m_buttonExitGame.getGlobalBounds().contains(sf::Mouse::getPosition(this->m_game->window).x, sf::Mouse::getPosition(this->m_game->window).y))
		{
			this->m_game->window.close();
		}
		else if (this->m_buttonStartGame.getGlobalBounds().contains(sf::Mouse::getPosition(this->m_game->window).x, sf::Mouse::getPosition(this->m_game->window).y))
		{
			this->m_game->changeState(new GameStatePlay(this->m_game));
		}
		break;
	}
	
}
