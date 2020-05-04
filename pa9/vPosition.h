#pragma once
#include <math.h>

/* A posiotion vector class to handle all the math for acceleration, velocity, and position of the boid enemies*/

class euclidVector
{
public: //All of the class is public due to the chance that we might need to directly modify the x and y values of any given vector
	float x, y;

	euclidVector(){
		x = 0;
		y = 0;
	}

	euclidVector(float x, float y) {
		this->x = x;
		this->y = y;
	}

	void set(float x, float y) {
		this->x = x;
		this->y = y;
	}

	
	void setMag(float);
	void capMag(double); //potentialy larger than the max float

	//Static vector functions
	static euclidVector copy(euclidVector);
	static euclidVector difVectors(euclidVector, euclidVector);
	static euclidVector sumVectors(euclidVector, euclidVector);
	static euclidVector proVectors(euclidVector, euclidVector);
	static euclidVector quoVectors(euclidVector, euclidVector);


	//Vector arythmetic
	void addVector(euclidVector);
	void subVector(euclidVector);
	void mulVector(euclidVector);
	void divVector(euclidVector);
	float angle(euclidVector);

	//vector-scalar arythmetic
	void addScalar(float s);
	void subScalar(float s);
	void mulScalar(float s);
	void divScalar(float s);

	//vector values
	float distance(euclidVector v);
	float magnitude();
	static float magnitude(euclidVector v);

	//vector opperations
	void normalize(); // make a unit vector


};

