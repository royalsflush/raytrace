#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#include "sphere.h"

#define sq(x) ((x)*(x))

Sphere::Sphere(const Vector& pcolor, const Vector& ppos, double pr) : 
	color(pcolor), pos(ppos), r(pr) { }


Vector& Sphere::getColor() {
	return color;
} 

Object* Sphere::checkIntersection(Ray& r) {
	double a = sq(r.dir);
	double b = (r.dir*2.0)*(r.o-this->pos);
	double c = sq(r.o-this->pos)-sq(this->r);

	double delta = b*b-4*a*c;
	
	if (delta<0) //Hit the background
		return NULL;

	double t1 = (-b-sqrt(delta))/2*a;
	double t2 = (-b+sqrt(delta))/2*a;

	double t = min(t1,t2);

	if (t>0) return (Object*) this;
	return NULL;
}
