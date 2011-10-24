#ifndef OPERATOR_H
#define OPERATOR_H

#include <vector>
using namespace std;

#include "node.h"

class Ray;
class Object;

class Operator : public Node {
	protected:
		vector<Node*> children;

	public:
		virtual void addChildren(Node* newNode) = 0;
		virtual Object* checkIntersection(Ray& r) = 0;	
};

#endif // OPERATOR_H
