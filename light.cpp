#include <math.h>

#include "vector.h"
#include "light.h"
#include "object.h"

Light::Light(const Vector& ppos, const Vector& pdir, double pang,
	const Vector& pamb, const Vector& pdif, const Vector& pspec) : pos(ppos), 
	dir(pdir), ang(pang), dif(pdif), spec(pspec), amb(pamb) {}

Vector& Light::getPos() {
	return pos;
}

Vector Light::calculateContrib(Vector& pv, Vector& pt, Object& obj) {
	Vector n = obj.getNormalAtPoint(pt);
	
	Vector l = this->pos-pt;
	l.normalize();
	Vector r = (n*(l*n))*2.0-l;
	r.normalize();
	Vector v = pv-pt;
	v.normalize();

	Material mat = obj.getMat();

	Vector col(0.0,0.0,0.0,0.0);
	col+= mat.amb*this->amb;
		
	if (l*n>0) {
		//Diffuse
		col.x+=this->dif.x*(l*n)*mat.dif.x;
		col.y+=this->dif.y*(l*n)*mat.dif.y;
		col.z+=this->dif.z*(l*n)*mat.dif.z;
		
		//Specular 
		double rva = pow(r*v,mat.shi);
		col.x+=this->spec.x*rva*mat.dif.x;
		col.y+=this->spec.y*rva*mat.dif.y;
		col.z+=this->spec.z*rva*mat.dif.z;
	}
	
	return col;
}
