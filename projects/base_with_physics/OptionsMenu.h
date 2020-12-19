#pragma once

#include "app.h"
#include "kage2dutil/physics.h"


class OptionsMenu 
{
private:
	sf::RenderWindow& m_window;
	sf::Sprite* cat;
public:
	OptionsMenu(sf::RenderWindow& window);
	 ~OptionsMenu();
	 bool start();
	 void update(float deltaT);
	 void render();
	 void cleanup();

};
