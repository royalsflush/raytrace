#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "object.h"
#include "vector.h"

class Object;
class Ray;

class Triangle : public Object {
	Vector p1,p2,p3;	

	public:
		Triangle(const Vector& pdif, const Vector& pspec,
			const double shi, const Vector& pp1,
			const Vector& pp2, const Vector& pp3);
	
		Object* checkIntersection(Ray& r);
		Vector getIntersectionPoint(Ray& r);
		Vector getNormalAtPoint(Vector& p);
};

#endif //TRIANGLE_H 
