#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "Entitiy.h"
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