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
	void update(float dt);

private:

	bool				m_movingUp = false, 
						m_movingDown = false,
						m_movingLeft = false,
						m_movingRight = false;

	float				m_velocityX = 0.0000f;
	float				m_maxVelocityX = 300.0000f;
	float				m_accelerationX = 200.0000f;	

	float				m_velocityY = 0.00000f;
	float				m_maxVelocityY = 300.0000f;
	float				m_accelerationY = 200.0000f;

	sf::Texture			m_spriteSheet;
	sf::Sprite			m_sprite;

};