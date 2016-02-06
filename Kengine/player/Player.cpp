#include "Player.h"

kengine::Player::Player()
{
	m_playerSprite.setColor(sf::Color(0, 255, 0, 255));
	
	m_imageSize.x = m_playerSprite.getLocalBounds().width;
	m_imageSize.y = m_playerSprite.getLocalBounds().height;
}

kengine::Player::Player(std::string imagePath, float factorX, float factorY)
{
	if (!m_playerTexture.loadFromFile(imagePath))
	{
		//Couldn't load texture from file
	}
	m_imagePath = imagePath;
	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setScale(factorX, factorY);

	m_imageSize.x = m_playerSprite.getLocalBounds().width;
	m_imageSize.y = m_playerSprite.getLocalBounds().height;
}

kengine::Player::~Player()
{
	
}

void kengine::Player::checkInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movePlayer(sf::Vector2f(m_playerSprite.getPosition().x - 1, m_playerSprite.getPosition().y));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movePlayer(sf::Vector2f(m_playerSprite.getPosition().x + 1, m_playerSprite.getPosition().y));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movePlayer(sf::Vector2f(m_playerSprite.getPosition().x, m_playerSprite.getPosition().y - 1));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movePlayer(sf::Vector2f(m_playerSprite.getPosition().x, m_playerSprite.getPosition().y + 1));
}

void kengine::Player::movePlayer(sf::Vector2f position)
{
	m_playerSprite.setPosition(position);
}

void kengine::Player::setSize(int width, int height)
{ 
	m_playerWidth = width; 
	m_playerHeight = height; 

	m_playerSprite.setScale(m_playerWidth / m_imageSize.x, m_playerHeight / m_imageSize.y);
}