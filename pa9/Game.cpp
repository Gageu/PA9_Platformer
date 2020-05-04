#ifndef GAME_C
#define GAME_C
#include "Game.h"

void BoidGame::initVariables()
{
	window = nullptr;
	entity_list = std::vector<sf::Drawable*>();
	BoidEnemy* boid1 = new BoidEnemy();
	BoidEnemy* boid2 = new BoidEnemy();
	entity_list.push_back((sf::Drawable*) boid1);
	flock.push_back(*boid1);
	boid1->velocity = euclidVector(5, 5);
	boid2->setPosition(100, 100);
	boid2->velocity = euclidVector(5, 5);
	entity_list.push_back((sf::Drawable*) boid2);
	flock.push_back(*boid2);
}

void BoidGame::initWindow()
{
	this->video_mode.height = 600;
	this->video_mode.width = 800;
	window = new sf::RenderWindow(video_mode, "BoidGame", sf::Style::Titlebar | sf::Style::Close);

}

BoidGame::BoidGame(int a)
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
	flock[1].update(flock);
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