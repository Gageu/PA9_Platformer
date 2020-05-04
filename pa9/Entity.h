#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class Entity : public sf::Drawable, public sf::Transformable
{
public:
	int health;

    float width, height;
	sf::VertexArray e_vert;
    sf::Texture* e_text;



	
	Entity();
	virtual ~Entity();

    //copied from https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php as part of the library ///
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    virtual sf::FloatRect getLocalBounds();
    virtual sf::FloatRect getGlobalBounds();
    virtual sf::IntRect getTextureRect();
    sf::Texture * getTexture();


    virtual void onCollsion(Entity e);





};
#endif // !ENTITY_H
