#include "testState.h"

testState::testState()
{
	m_player = new kengine::Player("images/tank-bottom.png", "images/tank-gun.png", 1, 1);
	//m_player->setSize(100, 100); 
}

testState::~testState()
{
}

void testState::pause()
{
}

void testState::resume()
{
}

void testState::handleEvents(sf::Time &deltaTime)
{
	m_player->checkInput(deltaTime);
}

void testState::update()
{
}

void testState::draw(sf::RenderWindow &gameWindow)
{
	gameWindow.draw(m_player->getPlayerSpriteBottom());
	gameWindow.draw(m_player->getPlayerSpriteGun());
}
