#include "OptionsMenu.h"


OptionsMenu::OptionsMenu(sf::RenderWindow& window) :
	m_window(window)
{
}

OptionsMenu::~OptionsMenu()
{
}


bool OptionsMenu::start()
{

		cat = kage::TextureManager::getSprite("data/cat.png");
 


	return true;
}

void OptionsMenu::update(float deltaT)
{
	// You need to update the physics system every game update


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{	 
	}	
}

void OptionsMenu::render()
{
	m_window.draw(*cat);


}

void OptionsMenu::cleanup()
{
	delete cat;
}

