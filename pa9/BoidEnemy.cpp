#include "BoidEnemy.h"
//debug

BoidEnemy::BoidEnemy()
{
	height = 30;
	width = 60;
	health = 1;
	e_vert = sf::VertexArray(sf::Quads, 4);
	maxVel = 10;
	maxAcc = .5;

	//e_text = sf::Texture();
	//e_text.loadFromFile("noText.png");

	e_vert[0].position = sf::Vector2f(0.0f, 0.0f);
	e_vert[1].position = sf::Vector2f(60.f, 15.f);
	e_vert[2].position = sf::Vector2f(0.0f, 30.f);
	e_vert[3].position = sf::Vector2f(20.f, 15.f);

	//// define its texture area to be a 60x30 rectangle starting at (0, 0)
	//e_vert[0].texCoords = sf::Vector2f(0.f, 0.f);
	//e_vert[1].texCoords = sf::Vector2f(60.f, 0.f);
	//e_vert[2].texCoords = sf::Vector2f(60.f, 30.f);
	//e_vert[3].texCoords = sf::Vector2f(0.f, 30.f);

	e_vert[0].color = sf::Color::Red;
	e_vert[1].color = sf::Color::Red;
	e_vert[2].color = sf::Color::Red;
	e_vert[3].color = sf::Color::Red;
}

BoidEnemy::BoidEnemy(sf::Color color)
{
	height = 30;
	width = 60;
	health = 1;
	e_vert = sf::VertexArray(sf::Quads, 4);
	maxVel = 10;
	maxAcc = .5;

	//e_text = sf::Texture();
	//e_text.loadFromFile("noText.png");

	e_vert[0].position = sf::Vector2f(0.0f, 0.0f);
	e_vert[1].position = sf::Vector2f(60.f, 15.f);
	e_vert[2].position = sf::Vector2f(0.0f, 30.f);
	e_vert[3].position = sf::Vector2f(20.f, 15.f);

	// define its texture area to be a 60x30 rectangle starting at (0, 0)
	e_vert[0].texCoords = sf::Vector2f(0.f, 0.f);
	e_vert[1].texCoords = sf::Vector2f(60.f, 0.f);
	e_vert[2].texCoords = sf::Vector2f(60.f, 30.f);
	e_vert[3].texCoords = sf::Vector2f(0.f, 30.f);

	e_vert[0].color = color;
	e_vert[1].color = color;
	e_vert[2].color = color;
	e_vert[3].color = color;
}

BoidEnemy::~BoidEnemy()
{
}

euclidVector BoidEnemy::Separation(std::vector<BoidEnemy> flock)
{
	//combination of all diretion adjusments
	euclidVector dir(0, 0);

	//number of boids comparared
	int count = 0;

	// For every boid in the system, check if it's too close
	for (int i = 0; i < flock.size(); i++) {

		// Calculate distance from current boid to boid we're looking at
		float distance = position.distance(flock[i].getPosition());
		// If this is a fellow boid and it's too close, move away from it

		if (distance > 0
			&& distance < SEPARATION_CONSTANT) {
			euclidVector diff = euclidVector::difVectors(position, flock[i].position);
			diff.normalize();
			diff.divScalar(distance);      // Weight by distance
			dir.addVector(diff);
			count++;
		}

		// If current boid is a predator and the boid we're looking at is also
		// a predator, then separate only slightly
		if ((distance > 0 && distance < SEPARATION_CONSTANT)
			&& (predator && flock[i].predator)) {

			euclidVector diff = euclidVector::difVectors(position, flock[i].position);
			diff.normalize();
			diff.divScalar(distance);
			dir.addVector(diff);
			count++;
		}

		// If current boid is not a predator, but the boid we're looking at is
		// a predator, then create a large separation vector
		else if ((distance > 0) && (distance < SEPARATION_CONSTANT + PREDATOR_AVOIDANCE) && flock[i].predator == true) {
			euclidVector diff = euclidVector::difVectors(position, flock[i].position);
			diff.mulScalar(PREDATOR_SCALAR);
			dir.addVector(diff);
			count++;
		}
	}

	// Adds average adjustment in position to the acceleration vector

	if (count > 0)
		dir.divScalar((float)count);
	if (dir.magnitude() > 0) {
		// Steering = Desired - Velocity
		dir.normalize();
		dir.mulScalar(maxVel);
		dir.subVector(velocity);
		dir.capMag(maxAcc); //might not work and cause jank
	}
	return dir;
}

euclidVector BoidEnemy::Alignment(std::vector<BoidEnemy> flock)
{
	euclidVector dir(0, 0);
	int count = 0;

	for (int i = 0; i < flock.size(); i++) {
		float d = position.distance(flock[i].getPosition());
		if ((d > 0) && (d < VIEW_DISTANCE)) { // 0 < d < 50
			dir.addVector(flock[i].velocity);
			count++;
		}
	}

	// If there are boids close enough for alignment...
	if (count > 0) {
		dir.divScalar((float)count);// Divide sum by the number of close boids (average of velocity)
		dir.normalize();            // Turn sum into a unit vector, and
		dir.mulScalar(maxVel);    // Multiply by maxSpeed

		// Steer = Desired - Velocity
		euclidVector adjust = euclidVector::difVectors(dir, velocity); //sum = desired(average)
		adjust.capMag(maxAcc);
		return adjust;
	}
	else {
		return euclidVector(0, 0);
	}
}

euclidVector BoidEnemy::Cohesion(std::vector<BoidEnemy> flock)
{
	euclidVector sum(0, 0);

	int count = 0;

	for (int i = 0; i < flock.size(); i++) {
		float d = position.distance(flock[i].getPosition());
		if ((d > 0) && (d < VIEW_DISTANCE)) {
			sum.addVector(flock[i].position);
			count++;
		}
	}
	if (count > 0) {
		sum.divScalar(count);
		return seek(sum);
	}
	else {
		return euclidVector(0, 0);
	}
}

euclidVector BoidEnemy::seek(euclidVector v)
{
	euclidVector desired;
	desired.subVector(v);  // A vector pointing from the location to the target
	// Normalize desired and scale to maximum speed
	desired.normalize();
	desired.mulScalar(maxVel);

	// Steering = Desired minus Velocity
	acceleration = euclidVector::difVectors(desired, velocity);
	acceleration.capMag(maxAcc);  // Limit to maximum steering force
	return acceleration;
}

void BoidEnemy::update(std::vector<BoidEnemy> flock)
{
	position = getPosition();
	euclidVector sep = Separation(flock);
	euclidVector ali = Alignment(flock);
	euclidVector coh = Cohesion(flock);
	// Arbitrarily weight these forces
	sep.mulScalar(1.5);
	ali.mulScalar(1.0); // Might need to alter weights for different characteristics
	coh.mulScalar(1.0);
	// Add the force vectors to acceleration
	acceleration.addVector(sep);
	acceleration.addVector(ali);
	acceleration.addVector(coh);


	//To make the slow down not as abrupt
	acceleration.mulScalar(.4);
	// Update velocity
	velocity.addVector(acceleration);
	// Limit speed
	velocity.capMag(maxVel);
	position.addVector(velocity);
	// Reset accelertion to 0 each cycle
	acceleration.mulScalar(0);

	// velocity = euclidVector::difVectors(position, getPosition());
	rotation = atan(velocity.y / velocity.x) * 57.2958 + 180;


	// std::cout << getPosition().x << "  " << getPosition().y << " : " << rotation << std::endl; //debug
	setPosition(position.x, position.y);
	setRotation((float)rotation);
}