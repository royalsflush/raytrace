#ifndef SPHERE_H
#define SPHERE_H

#include "node.h"
#include "vector.h"
#include "ray.h"

class Sphere : public Node {
	Vector color;
	Vector pos;
	double r;

	public:
		Sphere* checkIntersection(Ray& r);
		Sphere(const Vector& pcolor, const Vector& ppos, double pr);
		Vector& getColor();
};

#endif // SPHERE _H
