#include "BoidEnemy.h"


euclidVector BoidEnemy::Separation(std::vector<BoidEnemy> flock)
{
    //combination of all diretion adjusments
    euclidVector dir(0, 0);
    
    //number of boids comparared
    int count = 0;

    // For every boid in the system, check if it's too close
    for (int i = 0; i < flock.size(); i++) {

        // Calculate distance from current boid to boid we're looking at
        float distance = position.distance(flock[i].position);
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

euclidVector BoidEnemy::Allignment(std::vector<BoidEnemy> flock)
{
    euclidVector dir(0, 0);
    int count = 0;

    for (int i = 0; i < flock.size(); i++) {
        float d = position.distance(flock[i].position);
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
        return euclidVector(0,0);
    }
}

euclidVector BoidEnemy::Cohesion(std::vector<BoidEnemy> flock)
{
    euclidVector sum(0, 0);

    int count = 0;

    for (int i = 0; i < flock.size(); i++) {
        float d = position.distance(flock[i].position);
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
        return euclidVector(0,0);
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
