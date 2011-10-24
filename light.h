#ifndef LIGHT_H
#define LIGHT_H

#include "vector.h"

class Object;

class Light {
	Vector pos;
	Vector dir;	
	double ang;

	Vector dif;
	Vector spec;
	Vector amb;	

	public:
		Light(const Vector& ppos, const Vector& pdir,
			double pang, const Vector& pdif,
			const Vector& pspec, const Vector& pamb);

		Vector& getPos();	
		Vector calculateContrib(Vector& pv, Vector& pt, 
			Object& obj);
};

#endif //LIGHT_H
