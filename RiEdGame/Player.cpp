#include "Player.h"

Player::Player(std::string spriteSheetPath)
{
	this->create(spriteSheetPath);
}

sf::Sprite Player::getSprite()
{
	return this->m_sprite;
}

void Player::create(std::string spriteSheetPath)
{
	if (!this->m_spriteSheet.loadFromFile(spriteSheetPath));
	this->m_sprite.setTexture(this->m_spriteSheet);
	this->m_sprite.setTextureRect(sf::IntRect(0, 0, 120, 130));
}

void Player::handleInput(sf::Event event)
{
	switch(event.type)
	{
		case sf::Event::KeyPressed:
			if(event.key.code == sf::Keyboard::Up)
			{
				std::cout << "Up pressed";  
				this->m_velocity = this->m_velocity + this->m_acceleration;
				this->m_sprite.move(0.0f, this->m_velocity);
				std::cout << this->m_velocity << " " << this->m_acceleration;
			}
			else if(event.key.code == sf::Keyboard::Down)
			{ std::cout << "Down pressed"; }
			if (event.key.code == sf::Keyboard::Left)
			{ std::cout << "Left pressed"; }
			else if (event.key.code == sf::Keyboard::Right)
			{ std::cout << "Right pressed"; }
		break;
	}
}
