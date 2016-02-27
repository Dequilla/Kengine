#include "GameStatePlay.h"

GameStatePlay::GameStatePlay(Kengine::Game* game)
{
	this->m_game = game;

	this->m_hudView.reset(sf::FloatRect(this->m_game->window.getDefaultView().getViewport()));
	this->m_gameView.reset(sf::FloatRect(this->m_game->window.getDefaultView().getViewport()));

	this->m_hudView = this->m_game->window.getView();
	this->m_gameView = m_hudView;

	this->m_player.create("resources/images/linkEdit.png");

	if(!this->m_hudTexture.loadFromFile("resources/images/hud.png"));
	m_hudSprite.setTexture(m_hudTexture);
	m_hudSprite.setPosition(50.0f, 50.0f);
	m_hudSprite.setScale(0.5f, 0.5f);

	if (!this->m_mapTexture.loadFromFile("resources/images/map.png"));
	m_mapSprite.setTexture(m_mapTexture);
	m_mapSprite.setScale(4.5f, 4.5f);
	m_mapSprite.setOrigin(m_mapSprite.getLocalBounds().width / 2, m_mapSprite.getLocalBounds().height / 2);
	m_mapSprite.setPosition(.0f, .0f);
}

void GameStatePlay::draw(float dt)
{
	//Center the gameview on the player
	this->m_gameView.setCenter(this->m_player.getSprite().getPosition());
	
	//Game
	this->m_game->window.setView(m_gameView);
	this->m_game->window.draw(this->m_mapSprite);
	this->m_game->window.draw(this->m_player.getSprite());
	

	//HUD
	this->m_game->window.setView(m_hudView);
	this->m_game->window.draw(this->m_hudSprite);
}

void GameStatePlay::update(float dt)
{
	this->m_player.update(dt);
}

void GameStatePlay::handleInput(sf::Event event)
{
	this->m_player.handleInput(event);
}
