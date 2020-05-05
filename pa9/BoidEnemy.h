#pragma once
#include "vPosition.h"
#include <vector>
#include "Entity.h"

#define SEPARATION_CONSTANT 20.0f
#define PREDATOR_AVOIDANCE 70.0f
#define VIEW_DISTANCE 200.0f
#define PREDATOR_SCALAR 900

class BoidEnemy : public Entity 
{
public:

	BoidEnemy();
	~BoidEnemy();

	euclidVector position, velocity, acceleration;

	float maxAcc, maxVel;

	bool predator;


	//flocking functions

	euclidVector Separation(std::vector<BoidEnemy> flock);
	euclidVector Alignment(std::vector<BoidEnemy> flock);
	euclidVector Cohesion(std::vector<BoidEnemy> flock);

	euclidVector seek(euclidVector);

	void update(std::vector<BoidEnemy> flock);
};

