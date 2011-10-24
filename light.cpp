#include "vector.h"
#include "light.h"

Light::Light(const Vector& ppos, const Vector& pdir, double pang,
	const Vector& pdiff, const Vector& pspec) : pos(ppos), 
	dir(pdir), ang(pang), diff(pdiff), spec(pspec) {}
