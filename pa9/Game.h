#ifndef GAME_H
#define GAME_H

#include "BoidEnemy.h"
#include "Player.h"
#include "Collision.hpp"
#include <random>
#include <string>
#include <iostream>
#define Boids_Per_Wave 2
#define Wave_Timing 15
#define Starting_Boids 20
#define Game_Height 1080
#define Game_Width 1920

using namespace std;

class BoidGame {
private:
	//variables:
	std::vector<Entity*> entity_list;
	std::vector<BoidEnemy> flock;
	std::vector<BoidEnemy> flock2;
	std::vector<BoidEnemy> flock3;

	sf::Clock clock;
	sf::Text score;
	sf::Font font;
	sf::Text health;
	sf::RenderWindow* window;
	sf::VideoMode video_mode;
	sf::Event ev;

	//init functions:
	void initVariables();
	void initWindow();

	Player player;

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