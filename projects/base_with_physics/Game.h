#pragma once

#include "app.h"
#include "kage2dutil/physics.h"


class Game
{
private:
	sf::RenderWindow& m_window;
	sf::Sprite* frost;
public:
	Game(sf::RenderWindow& m_window);
	 ~Game();
	 bool start();
	 void update(float deltaT);
	 void render();
	 void cleanup();

};


