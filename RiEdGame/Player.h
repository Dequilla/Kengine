#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

class Player
{

public:
		
	Player() {};
	Player(std::string spriteSheetPath);
	~Player() {};

	sf::Sprite getSprite();

	void create(std::string spriteSheetPath);
	void handleInput(sf::Event event);
	void update();

private:

	bool				m_movingUp = false, 
						m_movingDown = false,
						m_movingLeft = false,
						m_movingRight = false;

	float				m_velocityX = 0.0f;
	float				m_maxVelocityX = 15.0f;
	float				m_accelerationX = 3.0f;	

	float				m_velocityY = 0.0f;
	float				m_maxVelocityY = 15.0f;
	float				m_accelerationY = 3.0f;

	sf::Texture			m_spriteSheet;
	sf::Sprite			m_sprite;

};