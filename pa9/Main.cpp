#include "Game.h"

int main()
{
	//TEST WINDOW CODE
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    sf::Drawable* test = new Entity();
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(*test);
        window.display();
    }

    return 0;
}