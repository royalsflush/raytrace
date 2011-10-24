#ifndef SPHERE_H
#define SPHERE_H

#include "vector.h"
#include "object.h"

class Ray;

class Sphere : public Object {
	Vector pos;
	double r;

	public:
		Sphere(const Vector& pdif, const Vector& pspec, 
			const Vector& ppos, double pr);
		Vector& getColor();
		
		Object* checkIntersection(Ray& r);
		Vector getIntersectionPoint(Ray& r);
		Vector getNormalAtPoint(Vector& p);
};

#endif // SPHERE _H
