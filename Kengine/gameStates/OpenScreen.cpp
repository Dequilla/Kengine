#include "OpenScreen.h"

OpenScreen::OpenScreen(kengine::Game* game) 
{
	m_game = game;

	if (!m_openingImage.loadFromFile("images/opening_image.png"))
	{
		std::cout << "Couldn't load opening image." << std::endl;
	}

	m_openingSprite.setColor(sf::Color(255, 255, 255, 0));
	m_openingSprite.setTexture(m_openingImage);


	m_clock.restart();
}

OpenScreen::~OpenScreen()
{
}

void OpenScreen::pause()
{
}

void OpenScreen::resume()
{
}

void OpenScreen::handleEvents(sf::Time & deltaTime)
{
}

void OpenScreen::update()
{
	if (!m_fading)
	{
		if (m_elapsedTime >= m_opacityChecker && m_opacity < 255)
		{
			m_opacityChecker += 0.05f;
			m_opacity += 5;

			m_openingSprite.setColor(sf::Color(255, 255, 255, m_opacity));
		}
		else if (m_opacity == 255)
		{
			m_fading = true;
		}
	}
	else if (m_fading)
	{
		if (m_elapsedTime >= m_opacityChecker && m_opacity > 0)
		{
			m_opacityChecker += 0.05f;
			m_opacity -= 5;

			m_openingSprite.setColor(sf::Color(255, 255, 255, m_opacity));
		}
		else if (m_opacity == 0)
		{
			m_elapsedTime = 0;
			m_fading = false;
			m_opacity = 0;
			m_opacityChecker = 0.05f;
			m_clock.restart();

			m_finished = true;
		}
	}

	m_elapsedTime = m_clock.getElapsedTime().asSeconds();
	if (m_finished)
	{
		quit();
		
		changeState(m_game, m_mainMenu);
	}
}

void OpenScreen::draw(sf::RenderWindow & gameWindow)
{
	gameWindow.draw(m_openingSprite);
}
