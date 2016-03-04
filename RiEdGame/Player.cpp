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
	this->m_sprite.setOrigin(this->m_sprite.getLocalBounds().width / 2, this->m_sprite.getLocalBounds().height / 2);
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

void Player::update(float dt)
{
	//Speed up

	//	UP
	if (this->m_movingUp == true)
	{
		if (this->m_velocityY > this->m_maxVelocityY * -1.0f)
		{
			this->m_velocityY = this->m_velocityY - this->m_accelerationY * (dt * 10.0f);
		}
	}

	//	DOWN
	if (this->m_movingDown == true)
	{
		if (this->m_velocityY < this->m_maxVelocityY)
		{
			this->m_velocityY = this->m_velocityY + this->m_accelerationY * (dt * 10.0f);
		}
	}

	//	LEFT
	if (this->m_movingLeft == true)
	{
		if (this->m_velocityX > this->m_maxVelocityX * -1.0f)
		{
			this->m_velocityX = this->m_velocityX - this->m_accelerationX * (dt * 10.0f);
		}
	}

	//	RIGHT
	if (this->m_movingRight == true)
	{
		if (this->m_velocityX < this->m_maxVelocityX)
		{
			this->m_velocityX = this->m_velocityX + this->m_accelerationX * (dt * 10.0f);
		}
	}


	//Slow down

	//	UP
	if (m_movingUp == false && m_velocityY < 0.0f)
	{
		this->m_velocityY = this->m_velocityY + this->m_accelerationY * (dt * 10.0f);
		if (m_velocityY > -(m_accelerationY * dt))
		{
			m_velocityY = 0.0;
		}
	}

	//	DOWN
	if (m_movingDown == false && m_velocityY > 0.0f)
	{
		this->m_velocityY = this->m_velocityY - this->m_accelerationY * (dt * 10.0f);
	}

	//	LEFT
	if (m_movingLeft == false && m_velocityX < 0.0f)
	{
		this->m_velocityX = this->m_velocityX + this->m_accelerationX * (dt * 10.0f);
		if (m_velocityX > -(m_accelerationX * dt))
		{
			m_velocityX = 0.0;
		}
	}

	//	RIGHT
	if (m_movingRight == false && m_velocityX > 0.0f)
	{
		this->m_velocityX = this->m_velocityX - this->m_accelerationX * (dt * 10.0f);
	}

	std::cout << "VelY: " << m_velocityY << " VelX: " << m_velocityX << " Acc X: " << this->m_accelerationX * (dt * 10.0f) << " Acc Y: " << this->m_accelerationY * (dt * 10.0f) << "  DT:  " << dt * 10.0f << std::endl;
	
	//Do not let it go any faster than max_velocity
	/*if (m_velocityX > m_maxVelocityX)
	{
		m_velocityX = m_maxVelocityX;
	}
	else if (m_velocityX < m_maxVelocityX * -1.0f)
	{
		m_velocityX = m_maxVelocityX * -1.0f;
	}
	
	if (m_velocityY > m_maxVelocityY)
	{
		m_velocityY = m_maxVelocityY;
	}
	else if (m_velocityY < m_maxVelocityY * -1.0f)
	{
		m_velocityY = m_maxVelocityY * -1.0f;
	}
	*/

	this->m_sprite.move((this->m_velocityX * dt), (this->m_velocityY * dt));
}
