#include "vector.h"
#include "ray.h"

Ray::Ray(Vector& po, Vector& pd) : o(po), dir(pd) {
	dir.normalize();
}

Ray& Ray::operator=(Ray& a) {
	this->o = a.o;
	this->dir = a.dir;

	return *this;
}
