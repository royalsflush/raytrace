#include <math.h>

#include "vector.h"
#include "light.h"
#include "object.h"

Light::Light(const Vector& ppos, const Vector& pdir, double pang,
	const Vector& pdif, const Vector& pspec) : pos(ppos), 
	dir(pdir), ang(pang), dif(pdif), spec(pspec) {}

Vector Light::calculateContrib(Vector& pv, Vector& pt, Object& obj) {
	Vector n = obj.getNormalAtPoint(pt);
	n.normalize();	
	Vector l = this->pos-pt;
	l.normalize();
	Vector r = (n*(l*n))*2.0-l;
	r.normalize();
	Vector v = pv-pt;
	v.normalize();

	Vector col(0.0,0.0,0.0,0.0);
		
	if (l*n>0) {
		//Diffuse
		col+=this->dif*(l*n)*obj.getDif();
		
		//Specular 
		double rva = pow(r*v,obj.getShi());
		col+=this->spec*rva*obj.getSpec();
	}

	return col;
}
