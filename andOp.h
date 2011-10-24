#ifndef AND_OP_H
#define AND_OP_H

#include "operator.h"

class AndOp : public Operator {
	public: 
		void addChildren(Node* newNode);
		Object* checkIntersection(Ray& r);	
};

#endif //AND_OP_H
