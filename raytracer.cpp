#include <math.h>

#include "raytracer.h"
#include "vector.h"
#include "ray.h"
#include "sphere.h"

const int negInf = 0xc0c0c0c0;

Raytracer::Raytracer(double width, double height, double near,
		double far) : w(width), h(height), znear(near), zfar(far) {

	eye.x = width/2.0;
	eye.y = height/2.0;
	eye.z = -znear;

	bgVec = Vector(0.0,0.0,0.0,0.0);	
	currMode = ORTHO;		

	Vector color(1.0,0.0,0.0,0.0);

	root = new Sphere(Vector(1.0,0.0,0.0,0.0), Vector(200.0, 200.0, 200.0), 40.0);
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
	
	Ray r(o,d);

	Sphere* s = root->checkIntersection(r);
	
	if (!s) return bgVec;
	return s->getColor();
}
