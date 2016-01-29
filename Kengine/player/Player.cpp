#include "Player.h"

Player::Player()
{

}

Player::Player(std::string imagePath, float factorX, float factorY)
{
	if (!m_playerTexture.loadFromFile(imagePath))
	{

	}
	m_playerSprite.setTexture(m_playerTexture);

	m_playerSprite.setScale(factorX, factorY);

	m_imageSize.x = m_playerSprite.getLocalBounds().width;
	m_imageSize.y = m_playerSprite.getLocalBounds().height;
}

Player::~Player()
{

}

void Player::checkInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->setSize(200, 200);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->setSize(30, 30);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) this->setSize(1000, 1000);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) std::cout << "Pressed S \n";
}

void Player::movePlayer()
{
	
}

void Player::setSize(int width, int height) 
{ 
	
	m_playerWidth = width; 
	m_playerHeight = height; 

	m_playerSprite.setScale(m_playerWidth / m_imageSize.x, m_playerHeight / m_imageSize.y);
}