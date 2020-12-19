#pragma once
#include "MainMenu.h"
#include "OptionsMenu.h"
#include "Game.h"

class SceneManager
{
private:

	MainMenu mainMenu;
	OptionsMenu optionsMenu;
	Game game;
	int m_index = 0;

public:
	SceneManager(sf::RenderWindow& window);
	~SceneManager();
	void Run(int index);

	void Start();
	void Update(float deltaTime);
	void Render();
};

