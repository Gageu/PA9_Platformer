
#include "Entity.h"
#include "Collision.hpp"
#include <vector>

class Game {
private:
	
	
	//variables:
	std::vector<sf::Drawable*> entity_list;
	sf::RenderWindow* window;
	sf::VideoMode video_mode;
	sf::Event ev;

	//init functions:
	void initVariables();
	void initWindow();

public:
	//constructor / destructor
	Game();
	virtual ~Game();

	//getters / setters
	bool isRunning();

	void update();
	void render();

};