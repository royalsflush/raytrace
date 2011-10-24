#include "vector.h"
#include "light.h"
#include "object.h"

Light::Light(const Vector& ppos, const Vector& pdir, double pang,
	const Vector& pdif, const Vector& pspec) : pos(ppos), 
	dir(pdir), ang(pang), dif(pdif), spec(pspec) {}

Vector Light::calculateContrib(Vector& pt, Object& obj) {
	Vector v;
	return v;
}
