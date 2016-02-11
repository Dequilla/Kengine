#include "MainMenu.h"

MainMenu::MainMenu()
{
	if (!m_fontNoRain.loadFromFile("fonts/AYearWithoutRain.ttf"))
	{
		std::cout << "Could not load font: \"A year without rain\"." << std::endl;
	}

	m_mainMenu.setString("Main menu!");
	m_mainMenu.setFont(m_fontNoRain);
	m_mainMenu.setPosition(500.0, 200.0);
	m_mainMenu.setCharacterSize(100);

	m_start.setString("Start game!");
	m_start.setFont(m_fontNoRain);
	m_start.setPosition(600.0, 350.0);
	m_start.setCharacterSize(40);

	m_exit.setString("Exit game!");
	m_exit.setFont(m_fontNoRain);
	m_exit.setPosition(610.0, 400.0);
	m_exit.setCharacterSize(40);
	std::cout << "loaded main menu";

}

MainMenu::MainMenu(kengine::Game * game)
{
	m_game = game;
	if (!m_fontNoRain.loadFromFile("fonts/AYearWithoutRain.ttf"))
	{
		std::cout << "Could not load font: \"A year without rain\"." << std::endl;
	}
	
	m_mainMenu.setString("Main menu!");
	m_mainMenu.setFont(m_fontNoRain);
	m_mainMenu.setPosition(20.0, 20.0);
	m_mainMenu.setCharacterSize(100);

	m_start.setString("Start game!");
	m_start.setFont(m_fontNoRain);

	m_exit.setString("Exit game!");
	m_exit.setFont(m_fontNoRain);
	std::cout << "loaded main menu";

}

MainMenu::~MainMenu()
{
}

void MainMenu::pause()
{
}

void MainMenu::resume()
{
}

void MainMenu::handleEvents(sf::Time & deltaTime)
{
}

void MainMenu::update()
{
}

void MainMenu::draw(sf::RenderWindow & gameWindow)
{
	gameWindow.draw(m_mainMenu);
	gameWindow.draw(m_start);
	gameWindow.draw(m_exit);
}
