#pragma once
#include <math.h>

/* A posiotion vector class to handle all the math for acceleration, velocity, and position of the boid enemies*/

class vPosition
{
public: //All of the class is public due to the chance that we might need to directly modify the x and y values of any given vector
	float x, y;

	vPosition(){
		x = 0;
		y = 0;
	}

	vPosition(float x, float y) {
		this->x = x;
		this->y = y;
	}

	void set(float x, float y) {
		this->x = x;
		this->y = y;
	}

	static vPosition copy(vPosition);
	void setMag(float);

	//Vector arythmetic
	void addVector(vPosition);
	void subVector(vPosition);
	void mulVector(vPosition);
	void divVector(vPosition);
	float angle(vPosition);

	//vector-scalar arythmetic
	void addScalar(float s);
	void subScalar(float s);
	void mulScalar(float s);
	void divScalar(float s);

	//vector values
	float distance(vPosition v);
	float magnitude();
	static float magnitude(vPosition v);

	//vector opperations
	void normalize() // make a unit vector


};

