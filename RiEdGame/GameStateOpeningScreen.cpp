#include "GameStateOpeningScreen.h"

GameStateOpeningScreen::GameStateOpeningScreen(Kengine::Game * game)
{
	this->m_game = game;
	sf::Vector2f pos = sf::Vector2f(this->m_game->window.getSize());
	m_view.setSize(pos);
	pos *= 0.5f;
	m_view.setCenter(pos);

	if (!m_openingImage.loadFromFile("resources/images/splashscreen.png"));

	m_openingSprite.setColor(sf::Color(255, 255, 255, 0));
	m_openingSprite.setTexture(m_openingImage);
	m_openingSprite.setOrigin((this->m_openingSprite.getGlobalBounds().width/2), (this->m_openingSprite.getGlobalBounds().height/2));
	m_openingSprite.setPosition((this->m_game->window.getSize().x / 2), (this->m_game->window.getSize().y / 2));

	m_clock.restart();
}

void GameStateOpeningScreen::draw(const float dt)
{
	this->m_game->window.draw(this->m_openingSprite);
}

void GameStateOpeningScreen::update(const float dt)
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
		this->m_game->changeState(new GameStateMainMenu(this->m_game));
	}
}

void GameStateOpeningScreen::handleInput(sf::Event event)
{
}