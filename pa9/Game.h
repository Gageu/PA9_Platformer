#ifndef GAME_H
#define GAME_H

#include "BoidEnemy.h"
#include <random>
#define Boids_Per_Wave 2
#define Wave_Timing 15
#define Starting_Boids 20
#define Game_Height 1080
#define Game_Width 1920


class BoidGame {
private:
	//variables:
	std::vector<Entity*> entity_list;
	std::vector<BoidEnemy> flock;
	std::vector<BoidEnemy> flock2;
	std::vector<BoidEnemy> flock3;

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