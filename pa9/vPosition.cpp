#include "vPosition.h"

vPosition vPosition::copy(vPosition v)
{
	vPosition cpy(v.x, v.y);
	return cpy;
}

void vPosition::setMag(float)
{
	normalize();
	mulScalar(x);
}

void vPosition::addVector(vPosition v)
{
	this->x += v.x;
	this->y += v.y;
}

void vPosition::subVector(vPosition v)
{
	this->x -= v.x;
	this->y -= v.y;
}

void vPosition::mulVector(vPosition v)
{
	this->x *= v.x;
	this->y *= v.y;
}

void vPosition::divVector(vPosition v)
{
	this->x += v.x;
	this->y += v.y;
}

float vPosition::angle(vPosition v)
{
	if ((x == 0 && y == 0) || (v.x == 0 && v.y == 0)) {
		return 0.0f;
	}
	

	double dot_product = x * v.x + y * v.y;
	double mag1 = magnitude();
	double mag2 = v.magnitude();
	double cos_theta = (dot_product / (mag1 * mag2));

	if (cos_theta <= -1) {
		return 3.14;
	}
	else if (cos_theta >= 1) {
		return 0;
	}

	return acos(cos_theta);
}

void vPosition::addScalar(float s)
{
	this->x += s;
	this->y += s;
}

void vPosition::subScalar(float s)
{
	this->x -= s;
	this->y -= s;
}

void vPosition::mulScalar(float s)
{
	this->x *= s;
	this->y *= s;
}

void vPosition::divScalar(float s)
{
	this->x /= s;
	this->y /= s;
}

float vPosition::distance(vPosition v)
{
	return sqrt(pow((x - v.x), 2) + pow((y - v.y), 2));
}

float vPosition::magnitude()
{
	return sqrt((x * x) + (y * y));;
}

float vPosition::magnitude(vPosition v)
{
	return sqrt((v.x*v.x) + (v.y*v.y));
}

void vPosition::normalize()
{
	float m = magnitude();
	
	if (m > 0) {
		x /= m;
		y /= m;
	}
}
