#ifndef RAY_H
#define RAY_H

#include "vector.h"

class Ray {
	public:
		Vector o;
		Vector dir;

		Ray(Vector& po, Vector& pd);
		Ray& operator=(Ray& a);
};

#endif //RAY_H
