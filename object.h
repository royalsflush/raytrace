#ifndef OBJECT_H
#define OBJECT_H

#include "node.h"
#include "material.h"

class Ray;
class Vector;

class Object : public Node {
	Material mat;	

	public:
		Object(const Material& pmat);

		virtual Object* checkIntersection(Ray& r) = 0;
		virtual Vector getIntersectionPoint(Ray& r) = 0;
		virtual Vector getNormalAtPoint(Vector& p) = 0;

		//Getters
		Material& getMat();
};

#endif // OBJECT_H
