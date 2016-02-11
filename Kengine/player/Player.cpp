#include "Player.h"

kengine::Player::Player()
{
	m_tankBottom.setColor(sf::Color(0, 255, 0, 255));
	m_tankGun.setColor(sf::Color(0, 255, 0, 255));

	m_imageSize.x = m_tankBottom.getLocalBounds().width;
	m_imageSize.y = m_tankBottom.getLocalBounds().height;
}

kengine::Player::Player(std::string imagePathBottom, std::string imagePathGun, float factorX, float factorY)
{
	if (!m_tankTextureBottom.loadFromFile(imagePathBottom))
	{
		//Couldn't load texture from file
	}
	if (!m_tankTextureGun.loadFromFile(imagePathGun))
	{
		//Couldn't load texture from file
	}

	m_tankBottom.setTexture(m_tankTextureBottom);
	m_tankGun.setTexture(m_tankTextureGun);
	
	m_tankBottom.setScale(factorX, factorY);
	m_tankGun.setScale(factorX, factorY);

	m_tankBottom.setOrigin(sf::Vector2f(0.5, 0.5));
	m_tankGun.setOrigin(sf::Vector2f(0.5, 0.5));

	m_tankBottom.setPosition(400.0f, 400.0f);
	m_tankGun.setPosition(400.0f, 275.0f);

	//useless but hey cant be bother to delete right now
	m_imageSize.x = m_tankBottom.getLocalBounds().width;
	m_imageSize.y = m_tankBottom.getLocalBounds().height;
}

kengine::Player::~Player()
{
	
}

void kengine::Player::checkInput(sf::Time &deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//Move
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		//Move
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//Move
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		//Move
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		std::cout << "turning turret" << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		std::cout << "turning turret" << std::endl;
	}

}

void kengine::Player::movePlayer(sf::Vector2f position)
{
	//m_playerSprite.setPosition(position);
}

void kengine::Player::setSize(int width, int height)
{ 
	m_playerWidth = width; 
	m_playerHeight = height; 

	m_tankBottom.setScale(m_playerWidth / m_imageSize.x, m_playerHeight / m_imageSize.y);
}
