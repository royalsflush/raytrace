#include "vector.h"
#include <stdio.h>

Vector::Vector(double px, double py, double pz,
	double pw) : x(px), y(py), z(pz), w(pw) { }

Vector::Vector(const Vector& a) : x(a.x), y(a.y), z(a.z), w(a.w) { }

Vector& Vector::operator=(const Vector& a) {
	this->x=a.x;
	this->y=a.y;
	this->z=a.z;
	this->w=a.w;

	return *this;
}

Vector& Vector::operator+=(const Vector& a) {
	this->x+=a.x;
	this->y+=a.y;
	this->z+=a.z;
	this->w+=a.w;

	return *this;
}

Vector& Vector::operator-=(const Vector& a) {
	this->x-=a.x;
	this->y-=a.y;
	this->z-=a.z;
	this->w-=a.w;

	return *this;
}

Vector Vector::operator+(const Vector& a) {
	Vector res(*this);
	res+=a;

	return res;
}

Vector Vector::operator-(const Vector& a) {
	Vector res(*this);
	res-=a;
	
	return res;
}

Vector& Vector::operator*=(const double a) {
	this->x*=a;
	this->y*=a;
	this->z*=a;
	this->w*=a;

	return *this;
}

Vector Vector::operator*(const double a) {
	Vector res(*this);
	res*=a;

	return res;
}
