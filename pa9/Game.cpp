#ifndef GAME_C
#define GAME_C
#include "Game.h"

void BoidGame::initVariables()
{
	window = nullptr;
	srand(time(NULL));
	entity_list = std::vector<Entity*>();

	for (int i = 0; i < Starting_Boids; i++) {
		BoidEnemy* boid = new BoidEnemy();
		if (i < 2) boid->predator = true;
		boid->setPosition(rand() % Game_Width, rand() % Game_Height);
		boid->velocity = euclidVector((rand() % 10) - 5, (rand() % 10) - 5);
		entity_list.push_back((Entity*) boid); // <--- Polymorphism
		flock.push_back(*boid);
	}

	for (int i = 0; i < Starting_Boids; i++) {
		BoidEnemy* boid = new BoidEnemy(sf::Color::Blue);
		if (i < 2) boid->predator = true;
		boid->setPosition(rand() % Game_Width, rand() % Game_Height);
		boid->velocity = euclidVector(rand() % 5, rand() % 5);
		entity_list.push_back((Entity*)boid); // <--- Polymorphism
		flock2.push_back(*boid);
	}

	for (int i = 0; i < Starting_Boids; i++) {
		BoidEnemy* boid = new BoidEnemy(sf::Color::White);
		if (i < 2 ) boid->predator = true;
		boid->setPosition(rand() % Game_Width, rand() % Game_Height);
		boid->velocity = euclidVector(rand() % 5, rand() % 5);
		entity_list.push_back((Entity*)boid); // <--- Polymorphism
		flock3.push_back(*boid);
	}

}

void BoidGame::initWindow()
{
	this->video_mode.height = 1080;
	this->video_mode.width = 1920;
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

	
	for (int i = 0; i < flock.size(); i++) {
		flock[i].update(flock);
		float x, y, borderx, bordery;
		borderx = window->getSize().x;
		bordery = window->getSize().y;
		x = flock[i].getPosition().x;
		y = flock[i].getPosition().y;
		if (x < 0)    flock[i].setPosition(x + borderx, y);
		if (y < 0)    flock[i].setPosition(x, y + bordery);
		if (x > borderx) flock[i].setPosition(x - borderx, y);
		if (y > bordery) flock[i].setPosition(x, y - bordery);
	}

	for (int i = 0; i < flock2.size(); i++) {
		flock2[i].update(flock2);
		float x, y, borderx, bordery;
		borderx = window->getSize().x;
		bordery = window->getSize().y;
		x = flock2[i].getPosition().x;
		y = flock2[i].getPosition().y;
		if (x < 0)    flock2[i].setPosition(x + borderx, y);
		if (y < 0)    flock2[i].setPosition(x, y + bordery);
		if (x > borderx) flock2[i].setPosition(x - borderx, y);
		if (y > bordery) flock2[i].setPosition(x, y - bordery);
	}

	for (int i = 0; i < flock3.size(); i++) {
		flock3[i].update(flock3);
		float x, y, borderx, bordery;
		borderx = window->getSize().x;
		bordery = window->getSize().y;
		x = flock3[i].getPosition().x;
		y = flock3[i].getPosition().y;
		if (x < 0)    flock3[i].setPosition(x + borderx, y);
		if (y < 0)    flock3[i].setPosition(x, y + bordery);
		if (x > borderx) flock3[i].setPosition(x - borderx, y);
		if (y > bordery) flock3[i].setPosition(x, y - bordery);
	}

}

void BoidGame::render()
{
	window->clear();
	for (int i = 0; i < flock.size(); i++) {
		window->draw(flock[i]);
	}

	for (int i = 0; i < flock2.size(); i++) {
		window->draw(flock2[i]);
	}

	for (int i = 0; i < flock3.size(); i++) {
		window->draw(flock3[i]);
	}

	window->display();
}
#endif // !GAME_C