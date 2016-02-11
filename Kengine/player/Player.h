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
		Player(std::string imagePathBottom, std::string imagePathGun, float factorX, float factorY);
		~Player();

		void checkInput(sf::Time &deltaTime);
		void movePlayer(sf::Vector2f position);

		sf::Sprite getPlayerSpriteBottom() { return m_tankBottom; }
		sf::Sprite getPlayerSpriteGun() { return m_tankGun; }

		sf::Vector2f getSize() { return sf::Vector2f(m_tankBottom.getGlobalBounds().width, m_tankBottom.getGlobalBounds().height); }
		void setSize(int width, int height);

	private:
		sf::Time m_deltaTime;
		sf::Sprite m_tankBottom, m_tankGun;
		sf::Texture m_tankTextureBottom, m_tankTextureGun;
		int m_playerWidth = 0, m_playerHeight = 0;
		sf::Vector2f m_imageSize;
		std::string m_imagePath;

	};

}