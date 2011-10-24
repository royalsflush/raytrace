#ifndef NODE_H
#define NODE_H

class Ray;
class Sphere;

class Node {
	public:
		virtual Sphere* checkIntersection(Ray& r) = 0;
};

#endif // NODE_H
