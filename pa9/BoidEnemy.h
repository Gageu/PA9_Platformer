#pragma once
#include "vPosition.h"
#include "Entity.h"

class BoidEnemy : public Entitiy 
{
public:
	euclidVector position, velocity, acceleration;

	float maxAcc, macVel;

	bool predator;
};

