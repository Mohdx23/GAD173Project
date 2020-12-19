#include "OptionsMenu.h"

OptionsMenu::OptionsMenu(sf::RenderWindow& window) :m_window(window)
{
}

OptionsMenu::~OptionsMenu()
{
}

bool OptionsMenu::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/GameBG.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	return true;
}

void OptionsMenu::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
	}
}

void OptionsMenu::render()
{
	m_window.draw(*m_backgroundSprite);
}

void OptionsMenu::cleanup()
{
}

