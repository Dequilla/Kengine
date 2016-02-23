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

	this->m_buttonStartGame.setFont(temp_font);
	this->m_buttonStartGame.setPosition(sf::Vector2f(300, 250));
	this->m_buttonStartGame.setSize(sf::Vector2f(200, 50));
	this->m_buttonStartGame.setString("Start game");
	this->m_buttonStartGame.setBackgroundColor(sf::Color(255, 0, 0, 255));
	this->m_buttonStartGame.setOverBackgroundColor(sf::Color(150, 0, 0, 255));
	this->m_buttonStartGame.setOverTextColor(sf::Color(200, 200, 200, 255));

	this->m_buttonExitGame.setFont(temp_font);
	this->m_buttonExitGame.setPosition(sf::Vector2f(300, 350));
	this->m_buttonExitGame.setSize(sf::Vector2f(200, 50));
	this->m_buttonExitGame.setString("Exit game");
	this->m_buttonExitGame.setBackgroundColor(sf::Color(255, 0, 0, 255));
	this->m_buttonExitGame.setOverBackgroundColor(sf::Color(150, 0, 0, 255));
	this->m_buttonExitGame.setOverTextColor(sf::Color(200, 200, 200, 255));

}

void GameStateMainMenu::draw(const float dt)
{
	//Always draw background first//
	this->m_game->window.draw(this->m_spriteBackground);
	////////////////////////////////

	this->m_game->window.draw(this->m_buttonStartGame);
	this->m_game->window.draw(this->m_buttonExitGame);
	this->m_game->window.draw(this->m_textMenu);
}

void GameStateMainMenu::update(const float dt)
{
	m_buttonStartGame.handler(this->m_game->window);
	m_buttonExitGame.handler(this->m_game->window);
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
	}

	m_buttonStartGame.events(event);
	if (m_buttonStartGame.clicked())
	{
		this->startGame();
	}
	m_buttonExitGame.events(event);
	if (m_buttonExitGame.clicked())
	{
		this->m_game->window.close();
	}
	
}

void GameStateMainMenu::startGame()
{
	this->m_game->changeState(new GameStatePlay(this->m_game));
}
