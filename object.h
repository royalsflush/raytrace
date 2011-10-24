#ifndef OBJECT_H
#define OBJECT_H

#include "node.h"
#include "vector.h"

class Ray;

class Object : public Node {
	Vector dif;
	Vector spec;

	public:
		Object(const Vector& pdif, const Vector& pspec);

		virtual Object* checkIntersection(Ray& r) = 0;
		virtual Vector getIntersectionPoint(Ray& r) = 0;
		virtual Vector getNormalAtPoint(Vector& p) = 0;

		//Getters
		Vector& getDif();
		Vector& getSpec();
};

#endif // OBJECT_H
