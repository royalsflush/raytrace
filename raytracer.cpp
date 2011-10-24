#include <math.h>

#include <vector>
using namespace std;

#include "raytracer.h"
#include "vector.h"
#include "ray.h"
#include "object.h"
#include "sphere.h"
#include "light.h"

const int negInf = 0xc0c0c0c0;

Raytracer::Raytracer(double width, double height, double near,
		double far) : w(width), h(height), znear(near), zfar(far) {

	eye.x = width/2.0;
	eye.y = height/2.0;
	eye.z = -znear;

	bgVec = Vector(0.0,0.0,0.0,0.0);	
	currMode = ORTHO;		

	root = new Sphere(Vector(1.0,0.0,0.0,0.0), 
		Vector(0.4, 0.4, 0.4, 0.0),
		Vector(500.0, 300.0, 200.0), 70.0);

	//Test source
	Light* light0 = new Light(Vector(600.0, 400.0, 0.0),
				Vector(-1.0,-1.0,0.0,0.0),
				45.0,
				Vector(0.5,0.5,0.5,0.0),
				Vector(0.2,0.2,0.2,0.0));

	Light* light1 = new Light(Vector(0.0, 0.0, 200.0),
				Vector(1.0,1.0,0.0,0.0),
				45.0,
				Vector(0.3,0.3,0.3,0.0),
				Vector(0.2,0.2,0.2,0.0));


	lights.push_back(light0);
	lights.push_back(light1);
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

	Object* obj = root->checkIntersection(r);
	
	if (!obj) return bgVec;

	Vector color(0.0,0.0,0.0,0.0);
	Vector pt = obj->getIntersectionPoint(r);

	for (int i=0; i<lights.size(); i++) 
		color+=lights[i]->calculateContrib(o,pt,*obj);

	return color;
}
