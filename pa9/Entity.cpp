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
	e_vert = sf::VertexArray(sf::Quads, 4);

	e_text = sf::Texture();
	e_text.loadFromFile("noText.png");

	e_vert[0].position = sf::Vector2f(10.f, 10.f);
	e_vert[1].position = sf::Vector2f(110.f, 10.f);
	e_vert[2].position = sf::Vector2f(110.f, 110.f);
	e_vert[3].position = sf::Vector2f(10.f, 110.f);

	// define its texture area to be a 25x50 rectangle starting at (0, 0)
	e_vert[0].texCoords = sf::Vector2f(0.f, 0.f);
	e_vert[1].texCoords = sf::Vector2f(25.f, 0.f);
	e_vert[2].texCoords = sf::Vector2f(25.f, 50.f);
	e_vert[3].texCoords = sf::Vector2f(0.f, 50.f);
}

Entity::~Entity()
{
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	{
		// apply the entity's transform -- combine it with the one that was passed by the caller
		states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

		// apply the texture
		states.texture = &e_text;

		// draw the vertex array
		target.draw(e_vert, states);
	}
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
	return &e_text;
}
void Entity::onCollsion(Entity e)
{
	health -= 1;
}
#endif // !ENTITY_C