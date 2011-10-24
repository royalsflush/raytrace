#ifndef NODE_H
#define NODE_H

class Ray;
class Object;

class Node {
	public:
		virtual Object* checkIntersection(Ray& r) = 0;
};

#endif // NODE_H
