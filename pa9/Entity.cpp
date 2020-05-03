#ifndef ENTITY_C
#define ENTITY_C

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "Collision.hpp"

Entity::Entity()
{
	height = 10;
	width = 10;
	health = 1;
	e_text = new sf::Texture();
	e_text->loadFromFile("noText.png");
}

Entity::~Entity()
{
	delete e_text;
}

sf::FloatRect Entity::getLocalBounds()
{
	return sf::FloatRect(0.f, 0.f, width, height);
}

sf::FloatRect Entity::getGlobalBounds()
{
	return getTransform().transformRect(getLocalBounds());
}

sf::IntRect Entity::getTextureRect()
{
	return sf::IntRect(0, 0, (int) width, (int) height);
}

sf::Texture * Entity::getTexture()
{
	return e_text;
}
void Entity::onCollsion(Entity e)
{
	health -= 1;
}
#endif // !ENTITY_C