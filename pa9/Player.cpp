#include "Player.h"

Player::Player()
{
	height = 10;
	width = 60;
	health = 100;
	e_vert = sf::VertexArray(sf::Quads, 4);
	//e_text = sf::Texture();
	e_text.loadFromFile("noText.png");
	setPosition(300, 300);

	e_vert[0].position = sf::Vector2f(0.0f, 0.0f);
	e_vert[1].position = sf::Vector2f(30.f, 0.f);
	e_vert[2].position = sf::Vector2f(30.f, 30.f);
	e_vert[3].position = sf::Vector2f(0.0f, 30.f);

	// define its texture area to be a 60x30 rectangle starting at (0, 0)
	//e_vert[0].texCoords = sf::Vector2f(0.f, 0.f);
	//e_vert[1].texCoords = sf::Vector2f(30.f, 0.f);
	//e_vert[2].texCoords = sf::Vector2f(30.f, 30.f);
	//e_vert[3].texCoords = sf::Vector2f(0.f, 30.f);

}

Player::~Player()
{
}

void Player::update(sf::Event event) {
	int x = 0;
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::D) {
			if (getPosition().x < 1865) {
				x += 30;
				setPosition(getPosition().x + x, getPosition().y);
			}
		}

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::A) {
				if (getPosition().x > 15) {
					x -= 30;
					setPosition(getPosition().x + x, getPosition().y);
				}
			}
		}
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::S) {
				if (getPosition().y < 1035) {
					x += 30;
					setPosition(getPosition().x, getPosition().y + x);
				}
			}
		}
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::W) {
				if (getPosition().y > 15) {
					x -= 30;
					setPosition(getPosition().x, getPosition().y + x);
				}
			}
		}
	}

}

//Updates health after collision. Returns true if still alive. False if dead.
bool Player::collision()
{
	bool status = true;
	health -= 8;
	if (health <= 0) {
		status = false;
	}
	return status;
}