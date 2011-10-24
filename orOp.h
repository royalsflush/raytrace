#ifndef OR_OP_H
#define OR_OP_H

#include "operator.h"

class Node;
class Object;
class Ray;

class OrOp : public Operator {
	public: 
		void addChildren(Node* newNode);
		Object* checkIntersection(Ray& r);	
};

#endif // OR_OP_H
