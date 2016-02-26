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
	m_hudSprite.setPosition(.0f, .0f);

	if (!this->m_mapTexture.loadFromFile("resources/images/map.jpg"));
	m_mapSprite.setTexture(m_mapTexture);
	m_mapSprite.setPosition(.0f, .0f);
	m_mapSprite.setScale(3.0f, 3.0f);
}

void GameStatePlay::draw(float dt)
{
	this->m_gameView.setCenter(this->m_player.getSprite().getPosition());
	//this->m_gameView.zoom(4.0f);
	//this->m_hudView.setViewport(sf::FloatRect(0.25f, 0.25, 0.5f, 0.5f));

	this->m_game->window.setView(m_hudView);
	this->m_game->window.draw(this->m_hudSprite);
	
	this->m_game->window.setView(m_gameView);
	this->m_game->window.draw(this->m_mapSprite);
	this->m_game->window.draw(this->m_player.getSprite());
	
}

void GameStatePlay::update(float dt)
{
}

void GameStatePlay::handleInput(sf::Event event)
{
	this->m_player.handleInput(event);
}
