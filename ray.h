#ifndef RAY_H
#define RAY_H

#include "vector.h"

class Ray {
	public:
		Vector o;
		Vector dir;

		Ray(const Vector& po, const Vector& pd);
		Ray& operator=(const Ray& a);
};

#endif //RAY_H
