#pragma once
#include "vPosition.h"
#include <vector>
#include "Entity.h"
#include <iostream>

#define SEPARATION_CONSTANT 80.0f
#define PREDATOR_AVOIDANCE 200.0f
#define VIEW_DISTANCE 400.0f
#define PREDATOR_SCALAR 900

class BoidEnemy : public Entity 
{
public:

	BoidEnemy();
	BoidEnemy(sf::Color color);
	~BoidEnemy();

	euclidVector position, velocity, acceleration;

	float maxAcc, maxVel, rotation;

	bool predator;


	//flocking functions

	euclidVector Separation(std::vector<BoidEnemy> flock);
	euclidVector Alignment(std::vector<BoidEnemy> flock);
	euclidVector Cohesion(std::vector<BoidEnemy> flock);

	euclidVector seek(euclidVector);

	void update(std::vector<BoidEnemy> flock);
};

