#include "Player.h"

Player::Player(std::string spriteSheetPath)
{
	this->create(spriteSheetPath);
	this->m_maxVelocityX = 15.0f;
	this->m_maxVelocityY = 15.0f;
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
				if(this->m_movingUp == false)
				{
					this->m_movingUp = true;
				}
			}
			else if(event.key.code == sf::Keyboard::Down)
			{ 
				if (this->m_movingDown == false)
				{
					this->m_movingDown = true;
				}
				
			}
			if (event.key.code == sf::Keyboard::Left)
			{ 
				if (this->m_movingLeft == false)
				{
					this->m_movingLeft = true;
				}
			}
			else if (event.key.code == sf::Keyboard::Right)
			{
				if (this->m_movingRight == false)
				{
					this->m_movingRight = true;
				}
			}
		break;

		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::Up)
			{
				this->m_movingUp = false;
			}
			else if (event.key.code == sf::Keyboard::Down)
			{
				this->m_movingDown = false;
			}
			if (event.key.code == sf::Keyboard::Left)
			{
				this->m_movingLeft = false;
			}
			else if (event.key.code == sf::Keyboard::Right)
			{
				this->m_movingRight = false;
			}
		break;

	}
}

void Player::update()
{
	//Speed up
	
	//	UP
	if(this->m_movingUp == true)
	{		
		if (this->m_velocityY > this->m_maxVelocityY * -1)
		{
			this->m_velocityY = this->m_velocityY - this->m_accelerationY;
		}
	}

	//	DOWN
	if (this->m_movingDown == true)
	{
		if (this->m_velocityY < this->m_maxVelocityY)
		{
			std::cout << this->m_maxVelocityY * -1;
			this->m_velocityY = this->m_velocityY + this->m_accelerationY;
		}
	}

	//	LEFT
	if (this->m_movingLeft == true)
	{
		if (this->m_velocityX > this->m_maxVelocityX * -1)
		{
			this->m_velocityX = this->m_velocityX - this->m_accelerationX;
		}
	}

	//	RIGHT
	if (this->m_movingRight == true)
	{
		if (this->m_velocityX < this->m_maxVelocityX)
		{
			this->m_velocityX = this->m_velocityX + this->m_accelerationX;
		}
	}


	//Slow down
	
	//	UP
	if (m_movingUp == false && m_velocityY < 0)
	{
		this->m_velocityY = this->m_velocityY + this->m_accelerationY;	
	}

	//	DOWN
	if (m_movingDown == false && m_velocityY > 0)
	{
		this->m_velocityY = this->m_velocityY - this->m_accelerationY;
	}

	//	LEFT
	if (m_movingLeft == false && m_velocityX < 0)
	{
		this->m_velocityX = this->m_velocityX + this->m_accelerationX;
	}

	//	RIGHT
	if (m_movingRight == false && m_velocityX > 0)
	{
		this->m_velocityX = this->m_velocityX - this->m_accelerationX;
	}


	this->m_sprite.move(this->m_velocityX, this->m_velocityY);
}