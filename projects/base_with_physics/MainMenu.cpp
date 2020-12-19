#include "MainMenu.h"
#include "SceneManager.h"



MainMenu::MainMenu(sf::RenderWindow& window, SceneManager& sceneManager) :
	m_window(window), m_sceneManager(sceneManager)
{
}

MainMenu::~MainMenu()
{
}


bool MainMenu::start()
{
	if (!font.loadFromFile("./data/bluehigh.ttf"))
	{
		std::cout << "font does not exist!" << std::endl;
	}

	for (size_t i = 0; i < TEXTS_ARRAY_SIZE; i++)
		texts[i].setFont(font);

	texts[0].setString("Start");
	texts[1].setString("Options");
	texts[2].setString("Exit");

	for (size_t i = 0; i < TEXTS_ARRAY_SIZE; i++)
	{
		texts[i].setPosition(sf::Vector2f(
			m_window.getSize().x / 2 - texts[i].getGlobalBounds().width / 2,
			(m_window.getSize().y / 2 - texts[i].getGlobalBounds().height / 2) + (i * LOCAL_TEXT_OFFSET_Y) + GLOBAL_TEXT_OFFSET_Y));
		
		texts[i].setColor(sf::Color::Red);
	}
	
	texts[selectedItem].setColor(sf::Color::White);

	return true;
}

void MainMenu::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && isKeyReleasedPreviously)
	{
		if (selectedItem < TEXTS_ARRAY_SIZE - 1)
			selectedItem++;
		else
			selectedItem = 0;

		for (size_t i = 0; i < TEXTS_ARRAY_SIZE; i++)
			texts[i].setColor(sf::Color::Red);
		
		texts[selectedItem].setColor(sf::Color::White);		

		isKeyReleasedPreviously = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isKeyReleasedPreviously)
	{
		if (selectedItem > 0)
			selectedItem--;
		else
			selectedItem = TEXTS_ARRAY_SIZE - 1;

		for (size_t i = 0; i < TEXTS_ARRAY_SIZE; i++)
			texts[i].setColor(sf::Color::Red);

		texts[selectedItem].setColor(sf::Color::White);

		isKeyReleasedPreviously = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		m_sceneManager.Run(selectedItem);
	}
	if (App::isKeyReleased) 
	{
		isKeyReleasedPreviously = true;
	}
	else
	{
		isKeyReleasedPreviously = false;

	}
}

void MainMenu::render()
{
	for (size_t i = 0; i < TEXTS_ARRAY_SIZE; i++)
		m_window.draw(texts[i]);
}

void MainMenu::cleanup()
{
}

