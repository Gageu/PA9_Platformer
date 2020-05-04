#include "vPosition.h"

euclidVector euclidVector::copy(euclidVector v)
{
	euclidVector cpy(v.x, v.y);
	return cpy;
}

euclidVector euclidVector::difVectors(euclidVector a, euclidVector b)
{
	
	return euclidVector(a.x - b.x, a.y - b.y);
}

euclidVector euclidVector::sumVectors(euclidVector a, euclidVector b)
{
	return euclidVector(a.x + b.x, a.y + b.y);
}

euclidVector euclidVector::proVectors(euclidVector a, euclidVector b)
{
	return euclidVector(a.x * b.x, a.y * b.y);
}

euclidVector euclidVector::quoVectors(euclidVector a, euclidVector b)
{
	return euclidVector(a.x / b.x, a.y / b.y);
}

void euclidVector::setMag(float)
{
	normalize();
	mulScalar(x);
}

void euclidVector::capMag(double cap)
{
	if (magnitude() > cap) {
		normalize();
		mulScalar(cap);
	}
}

void euclidVector::addVector(euclidVector v)
{
	this->x += v.x;
	this->y += v.y;
}

void euclidVector::subVector(euclidVector v)
{
	this->x -= v.x;
	this->y -= v.y;
}

void euclidVector::mulVector(euclidVector v)
{
	this->x *= v.x;
	this->y *= v.y;
}

void euclidVector::divVector(euclidVector v)
{
	this->x += v.x;
	this->y += v.y;
}

float euclidVector::angle(euclidVector v)
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

void euclidVector::addScalar(float s)
{
	this->x += s;
	this->y += s;
}

void euclidVector::subScalar(float s)
{
	this->x -= s;
	this->y -= s;
}

void euclidVector::mulScalar(float s)
{
	this->x *= s;
	this->y *= s;
}

void euclidVector::divScalar(float s)
{
	this->x /= s;
	this->y /= s;
}

float euclidVector::distance(euclidVector v)
{
	return sqrt(pow((x - v.x), 2) + pow((y - v.y), 2));
}

float euclidVector::magnitude()
{
	return sqrt((x * x) + (y * y));;
}

float euclidVector::magnitude(euclidVector v)
{
	return sqrt((v.x*v.x) + (v.y*v.y));
}

void euclidVector::normalize()
{
	float m = magnitude();
	
	if (m > 0) {
		x /= m;
		y /= m;
	}
}
