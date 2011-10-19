#include <math.h>

#include "raytracer.h"
#include "vector.h"

Raytracer::Raytracer(double width, double height, double near,
		double far) : w(width), h(height), znear(near), zfar(far) {

	pos.x=500.0;
	pos.y=550.0;
	pos.z=50.0;
	sr = 25.0;

	eye.x = width/2.0;
	eye.y = height/2.0;
	eye.z = -znear;

	r=g=b=a=0.0;		
}

Vector Raytracer::getColor(double px, double py) {
	Vector p(px,py);
	Vector d = p-eye;	
	d.normalize();
	
	double a = d*d;
	double b = (d*2.0)*(eye-pos);
	double c = (eye-pos)*(eye-pos)-sr*sr;

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
