#pragma once
#include "vPosition.h"
#include <vector>
#include "Entity.h"

class Player : public Entity {
public:
	Player();
	~Player();
	void update(sf::Event event);

	int health;

};