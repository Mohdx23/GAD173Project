#include "Game.h"


Game::Game(sf::RenderWindow& window) :
	m_window(window)
{
}

Game::~Game()
{
}

bool Game::start()
{
	frost = kage::TextureManager::getSprite("data/frost.png");

	return true;
}

void Game::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
	}
}

void Game::render()
{
	m_window.draw(*frost);
}

void Game::cleanup()
{
	delete frost;
}

