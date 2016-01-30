#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

namespace kengine {

	class Player
	{
	public:
		Player();
		Player(std::string imagePath, float factorX, float factorY);
		~Player();

		void checkInput();
		void movePlayer(sf::Vector2f position);

		sf::Sprite getPlayerSprite() { return m_playerSprite; }
		sf::Vector2f getSize() { return sf::Vector2f(m_playerSprite.getGlobalBounds().width, m_playerSprite.getGlobalBounds().height); }
		void setSize(int width, int height);

	private:
		sf::Sprite m_playerSprite;
		sf::Texture m_playerTexture;
		int m_playerWidth, m_playerHeight;
		sf::Vector2f m_imageSize;

	};

}