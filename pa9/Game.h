#ifndef GAME_H
#define GAME_H

#include "BoidEnemy.h"
#include <vector>


class BoidGame {
private:
	//variables:
	std::vector<sf::Drawable*> entity_list;
	std::vector<BoidEnemy> flock;

	sf::RenderWindow* window;
	sf::VideoMode video_mode;
	sf::Event ev;

	//init functions:
	void initVariables();
	void initWindow();

public:
	//constructor / destructor
	BoidGame(int);
	virtual ~BoidGame();

	//getters / setters
	bool isRunning();

	void update();
	void render();

};
#endif // !GAME_H