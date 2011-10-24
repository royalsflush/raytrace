#include "node.h"
#include "object.h"
#include "ray.h"
#include "andOp.h"

const int inf=0x3f3f3f3f;

void AndOp::addChildren(Node* newNode) {
	children.push_back(newNode);
}

Object* AndOp::checkIntersection(Ray& r) {
	int minZ = inf;
	Object* best=NULL;

	for (int i=0; i<children.size(); i++) {
		Object* obj =children[i]->checkIntersection(r);

		if (!obj)
			return NULL;

		Vector pt = obj->getIntersectionPoint(r);
			
		if (minZ>pt.z) {
			minZ = pt.z;
			best=obj;
		}
	}

	return best;
}
