#include "Game.h"

class Game{
private:


	sf::RenderWindow* Window;
	sf::Event ev;
	

	void initVariables();
	void initWindow();

public:
	Game();
	virtual ~Game();

	void update();
	void render();

};