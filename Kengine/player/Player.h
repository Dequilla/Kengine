#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

namespace kengine
{

	class Player
	{
	public:
		Player();
		Player(std::string imagePath, float factorX, float factorY);
		~Player();

		void checkInput(sf::Time &deltaTime);
		void movePlayer(sf::Vector2f position);

		sf::Sprite getPlayerSprite() { return m_playerSprite; }
		sf::Vector2f getSize() { return sf::Vector2f(m_playerSprite.getGlobalBounds().width, m_playerSprite.getGlobalBounds().height); }
		void setSize(int width, int height);

	private:
		sf::Time m_deltaTime;
		sf::Sprite m_playerSprite;
		sf::Texture m_playerTexture;
		int m_playerWidth = 0, m_playerHeight = 0;
		sf::Vector2f m_imageSize;
		std::string m_imagePath;

	};

}