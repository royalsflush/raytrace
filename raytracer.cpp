#include <math.h>

#include "raytracer.h"
#include "vector.h"

const int negInf = 0xc0c0c0c0;

Raytracer::Raytracer(double width, double height, double near,
		double far) : w(width), h(height), znear(near), zfar(far) {

	pos.x=500.0;
	pos.y=550.0;
	pos.z=130.0;
	sr = 200.0;

	eye.x = width/2.0;
	eye.y = height/2.0;
	eye.z = -znear;

	r=g=b=a=0.0;	
	currMode = ORTHO;		
}

Vector Raytracer::getColor(double px, double py) {
	Vector d,o;

	switch (currMode) {
		case ORTHO:
			d = Vector(0.0f,0.0f,1.0f,0.0f);
			o = Vector(px,py,negInf);
			break;

		case PERSPECTIVE: {
			Vector p(px,py);
			d = p-eye;
			o = eye;
			break;
		}
	}
	
	d.normalize();

	double a = d*d;
	double b = (d*2.0)*(o-pos);
	double c = (o-pos)*(o-pos)-sr*sr;

	double delta = b*b-4*a*c;
	
	if (delta<0) //Hit the background
		return Vector(this->r,this->b,
			this->g, this->a);

	double t1 = (-b-sqrt(delta))/2*a;
	double t2 = (-b+sqrt(delta))/2*a;

	double t = min(t1,t2);
	if (t>0) return Vector(1.0,0.0,0.0,0.0);
	
	return Vector(this->r,this->b,
		this->g, this->a);
}
