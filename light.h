#ifndef LIGHT_H
#define LIGHT_H

#include "vector.h"

class Light {
	Vector pos;
	Vector dir;	
	double ang;

	Vector diff;
	Vector spec;
	
	public:
		Light(const Vector& ppos, const Vector& pdir,
			double pang, const Vector& pdiff,
			const Vector& pspec);
};

#endif //LIGHT_H
