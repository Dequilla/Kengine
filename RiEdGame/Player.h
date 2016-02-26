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

private:

	float m_velocity = 0.0f;
	float m_maxVelocity = 20.0f;
	float m_acceleration = 3.0f;	

	sf::Texture			m_spriteSheet;
	sf::Sprite			m_sprite;

};