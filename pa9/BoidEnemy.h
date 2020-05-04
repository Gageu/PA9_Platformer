#pragma once
#include "vPosition.h"
#include <vector>
#include "Entity.h"

#define SEPARATION_CONSTANT 20.0f
#define PREDATOR_AVOIDANCE 70.0f
#define VIEW_DISTANCE 50.0f
#define PREDATOR_SCALAR 900

class BoidEnemy : public Entity 
{
public:
	euclidVector position, velocity, acceleration;

	float maxAcc, maxVel;

	bool predator;


	//flocking functions

	euclidVector Separation(std::vector<BoidEnemy> flock);
	euclidVector Allignment(std::vector<BoidEnemy> flock);
	euclidVector Cohesion(std::vector<BoidEnemy> flock);

	euclidVector seek(euclidVector);
};

