#ifndef GAME_C
#define GAME_C
#include "Game.h"

void BoidGame::initVariables()
{
	window = nullptr;
	entity_list = std::vector<sf::Drawable*>();
	BoidEnemy* boid = new BoidEnemy();
	entity_list.push_back((sf::Drawable*) boid);
	flock.push_back(*boid);
}

void BoidGame::initWindow()
{
	this->video_mode.height = 600;
	this->video_mode.width = 800;
	window = new sf::RenderWindow(video_mode, "BoidGame", sf::Style::Titlebar | sf::Style::Close);

}

inline BoidGame::BoidGame()
{
	initVariables();
	initWindow();
}

BoidGame::~BoidGame()
{
	delete window;
}

bool BoidGame::isRunning()
{
	return window->isOpen();
}

void BoidGame::update()
{
	/*event poling*/
	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
			//window close event
		case sf::Event::Closed:
			window->close();
			break;

			/*inputs go here*/
		}
	}

	flock[0].update(flock);
}

void BoidGame::render()
{
	window->clear();

	for (int i = 0; i < entity_list.size(); i++) {
		window->draw(*(entity_list[i]));
	}

	window->display();
}
#endif // !GAME_C