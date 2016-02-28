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

	this->m_buttons[0].setFont(this->temp_font);
	this->m_buttons[0].setPosition(sf::Vector2f(300, 250));
	this->m_buttons[0].setSize(sf::Vector2f(200, 50));
	this->m_buttons[0].setString("Start Game");

	this->m_buttons[1].setFont(this->temp_font);
	this->m_buttons[1].setPosition(sf::Vector2f(300, 350));
	this->m_buttons[1].setSize(sf::Vector2f(200, 50));
	this->m_buttons[1].setString("Options");

	this->m_buttons[2].setFont(this->temp_font);
	this->m_buttons[2].setPosition(sf::Vector2f(300, 450));
	this->m_buttons[2].setSize(sf::Vector2f(200, 50));
	this->m_buttons[2].setString("Exit Game");
}

void GameStateMainMenu::draw(const float dt)
{
	//Always draw background first//
	this->m_game->window.draw(this->m_spriteBackground);
	////////////////////////////////

	for (int i = 0; i < 3; i++)
	{
		if (i == m_currentChoice)
		{
			this->m_buttons[i].setBackgroundColor(sf::Color(125, 125, 125, 255));
			this->m_buttons[i].setTextColor(sf::Color(0, 51, 102, 255));
		}
		else
		{
			this->m_buttons[i].setBackgroundColor(sf::Color(0, 0, 0, 255));
			this->m_buttons[i].setTextColor(sf::Color(255, 255, 255, 255));
		}
	}

	for (int i = 0; i < 3; i++)
	{
		this->m_game->window.draw(this->m_buttons[i]);
	}

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
		if (event.key.code == sf::Keyboard::Up)
		{
			m_currentChoice--;
			if (m_currentChoice == -1)
			{
				m_currentChoice = 2;
			}
		}
		else if (event.key.code == sf::Keyboard::Down)
		{
			m_currentChoice++;
			if (m_currentChoice == 3)
			{
				m_currentChoice = 0;
			}
		}
	
	//	if (event.key.code == sf::Keyboard::Left) /*Do something*/;
	//	else if (event.key.code == sf::Keyboard::Right) /*Do something*/;

		if (event.key.code == sf::Keyboard::Return)
		{
			if (m_currentChoice == 0)
			{
				this->startGame();
			}
			else if (m_currentChoice == 2)
			{
				this->m_game->window.close();
			}
		}

		break;
	}

	/*
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
	*/
}

void GameStateMainMenu::startGame()
{
	this->m_game->changeState(new GameStatePlay(this->m_game));
}
