#pragma once
#include "vPosition.h"
#include "Entity.h"

class BoidEnemy : public Entity 
{
public:
	euclidVector position, velocity, acceleration;

	float maxAcc, macVel;

	bool predator;
};

