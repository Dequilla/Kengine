#include "GameStatePlay.h"

GameStatePlay::GameStatePlay(Kengine::Game* game)
{
	this->m_game = game;
}

void GameStatePlay::draw(float dt)
{
	std::cout << "Game is working" << std::endl;
}

void GameStatePlay::update(float dt)
{
}

void GameStatePlay::handleInput(sf::Event event)
{
}
