#include "testState.h"

testState::testState()
{
	m_player = new kengine::Player("images/test.png", 1, 1);
	m_player->setSize(100, 100); 
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

void testState::handleEvents()
{
	m_player->checkInput();
}

void testState::update()
{
}

void testState::draw(sf::RenderWindow &gameWindow)
{
	gameWindow.draw(m_player->getPlayerSprite());
}
