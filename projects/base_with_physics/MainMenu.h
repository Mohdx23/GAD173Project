#pragma once
#include "app.h"
#include "kage2dutil/physics.h"

#define TEXTS_ARRAY_SIZE 3
#define LOCAL_TEXT_OFFSET_Y 100
#define GLOBAL_TEXT_OFFSET_Y 200

class SceneManager;

class MainMenu
{

private:
	sf::RenderWindow& m_window;
	SceneManager& m_sceneManager;
	sf::Font font;
	sf::Text texts[TEXTS_ARRAY_SIZE];


public:
	MainMenu(sf::RenderWindow& window, SceneManager& sceneManager);
	~MainMenu();
	bool start();
	void update(float deltaT);
	void render();
	void cleanup();


	int selectedItem = 0;
	bool isKeyReleasedPreviously = true;
};

