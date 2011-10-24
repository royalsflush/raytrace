#ifndef OBJECT_H
#define OBJECT_H

#include "node.h"
#include "vector.h"

class Ray;

class Object : public Node {
	public:
		virtual Object* checkIntersection(Ray& r) = 0;
		virtual Vector getIntersectionPoint(Ray& r) = 0;
		virtual Vector getNormalAtPoint(Vector& p) = 0;
};

#endif // OBJECT_H
