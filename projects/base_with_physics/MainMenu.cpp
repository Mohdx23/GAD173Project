#include "MainMenu.h"
#include "SceneManager.h"

MainMenu::MainMenu(sf::RenderWindow& window, SceneManager& sceneManager) : m_window(window), m_sceneManager(sceneManager)
{
}

MainMenu::~MainMenu()
{
}

bool MainMenu::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/Cool.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	if (!font.loadFromFile("./data/High.otf"))
	{
		std::cout << "font does not exist!" << std::endl;
	}

	for (size_t i = 0; i < TEXTS_ARRAY_SIZE; i++)
		texts[i].setFont(font);

	texts[0].setString("START");
	texts[1].setString("OPTIONS");
	texts[2].setString("EXIT");

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
	m_window.draw(*m_backgroundSprite);

	for (size_t i = 0; i < TEXTS_ARRAY_SIZE; i++)
		m_window.draw(texts[i]);
}

void MainMenu::cleanup()
{
}

