#include <stdio.h>
#include <math.h>

#include "vector.h"

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

double Vector::operator*(const Vector& a) {
	double dot=0.0;	

	dot+=this->x*a.x;
	dot+=this->y*a.y;
	dot+=this->z*a.z;
	dot+=this->w*a.w;

	return dot;
}

double Vector::length() {
	double dot = (*this)*(*this);
	return sqrt(dot);
}

void Vector::normalize() {
	double l=this->length();
	
	this->x/=l;
	this->y/=l;
	this->z/=l;
	this->w/=l;
}

void Vector::print() {
	printf("(%lf, %lf, %lf, %lf)\n", this->x,this->y,
		this->z,this->w);
}
