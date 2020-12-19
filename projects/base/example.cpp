#include "example.h"

Example::Example(): App()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	

	m_backgroundSprite = kage::TextureManager::getSprite("data/Spacey.jpg");

	OrangeTilee = kage::TextureManager::getTexture("data/OrangeTilee.png");
	PurpleTile = kage::TextureManager::getTexture("data/PurpleTile.png");
	//To load the textures that i've saved in the data folder

	
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	
	for (size_t i = 0; i < TOTAL_CELLS_X; i++)
	{
		vLine[i] = sf::RectangleShape(sf::Vector2f(LINE_THICKNESS, CELL_HEIGHT * TOTAL_CELLS_Y));
		vLine[i].setFillColor(sf::Color::Cyan);
		vLine[i].setPosition(sf::Vector2f(GRID_OFFSET_X + CELL_WIDTH * i, GRID_OFFSET_Y));
	}
	
	for (size_t i = 0; i < TOTAL_CELLS_Y; i++)
	{
		hLine[i] = sf::RectangleShape(sf::Vector2f(CELL_WIDTH * TOTAL_CELLS_X, LINE_THICKNESS));
		hLine[i].setFillColor(sf::Color::Cyan);
		hLine[i].setPosition(sf::Vector2f(GRID_OFFSET_X, GRID_OFFSET_Y + CELL_HEIGHT * i));
	}

	return true;

}

void Example::update(float deltaT)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

	//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
	//if statement for if the boolian pinkisActive or orangeisActive

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		int x = mousePosition.x / CELL_WIDTH;
		int y = mousePosition.y / CELL_HEIGHT;


		if (x >= 0 && y >= 0 && x < (TOTAL_CELLS_X - 1) && y < (TOTAL_CELLS_Y - 1))
		{
			int i = x + y * (TOTAL_CELLS_X - 1);

			sf::Sprite sprite;

			switch (tileID)
			{
			case 0:
				break;
			case 1:
				sprite.setTexture(*OrangeTilee);
				break;
			case 2:
				sprite.setTexture(*PurpleTile);
				break;
			}

			sprite.setPosition(sf::Vector2f(x * CELL_WIDTH, y * CELL_HEIGHT));
			tiles[i].sprite = sprite;
			tiles[i].id = tileID;
		}
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
			m_running = false;
		}

		ImGui::Begin("Kage2D");
		if (ImGui::Button("Exit"))
		{
			m_running = false;
		}
		if (ImGui::Button("Empty"))
		{
			tileID = 0;
		}
		if (ImGui::Button("Orange Tile"))
		{
			tileID = 1;
		}
		if (ImGui::Button("Purple Tile"))
		{
			tileID = 2;
		}
		if (ImGui::Button("Save"))
		{
			Save();
		}
		if (ImGui::Button("Load"))
		{
			Loading();
		}
		ImGui::End();
	}
	
void Example::Save()
{
	std::ofstream myfile;
	myfile.open("map.data");

	for (size_t i = 0; i < TILES_ARRAZY_SIZE; i++)
	{
		myfile << tiles[i].id << ", ";
	}

	myfile.close();
 }
void Example::Loading()
{
	std::string line;
	std::ifstream myfile("map data");

	if (myfile.is_open())
	{
		int ic = 0;
		std::getline(myfile, line);

		for (size_t i = 0; i < 10; i++)
		{
			ic = line.find(',', ic + 1);
			std::string ss = line.substr(ic - 1, (line.find(',', ic + 1)) - ic - 2);
			std::cout << ss << std::endl;
		}

		//int ic1 = line.find(',', 0);
		//std::string ss1 = line.substr(0, ic1);

		//int ic2 = line.find(',', ic1 + 1);
		//std::string ss2 = line.substr(ic1 + 1, ic2 - ic1 - 1);

		//std::cout << line << '/n';
		//std::cout << ss2 << std::endl;

		myfile.close();
	}
	else
		std::cout << "Unable to open file";
 }

	void Example::render()
	{
	m_window.draw(*m_backgroundSprite);

	for (size_t i = 0; i < TOTAL_CELLS_X; i++)
	{
		m_window.draw(vLine[i]);
	}

	for (size_t i = 0; i < TOTAL_CELLS_Y; i++)
	{
		m_window.draw(hLine[i]);
	}

	for (size_t i = 0; i < TILES_ARRAZY_SIZE; i++)
	{
		m_window.draw(tiles[i].sprite);
	}

}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

