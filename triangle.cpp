#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "triangle.h"
#include "ray.h"
#include "object.h"
#include "vector.h"

const double eps = 1e-9;

Triangle::Triangle(const Vector& pdif, const Vector& pspec,
	const double shi, const Vector& pp1,
	const Vector& pp2, const Vector& pp3) :
	Object(pdif,pspec,shi), p1(pp1), p2(pp2), p3(pp3) {}


Object* Triangle::checkIntersection(Ray& r) {
	Vector n = (p2-p1).cross(p3-p1);
	n.normalize();

	double den = r.dir*n;
	if (fabs(den)<eps)
		return NULL;

	double t = ((p1-r.o)*n)/den;
	Vector p = r.o+(r.dir)*t;

	Vector a = (p-p1).cross(p3-p1);
	Vector b = (p-p1).cross(p2-p1);

	Vector c = (p-p2).cross(p3-p2);
	Vector d = (p-p2).cross(p1-p2);

	if (a.z*b.z<0 && c.z*d.z<0) return this;
	return NULL;
}

Vector Triangle::getIntersectionPoint(Ray& r){
	Vector n = (p2-p1).cross(p3-p1);

	double den = r.dir*n;
	if (fabs(den)<eps)
		return NULL;

	double t = (p1-r.o)*n/den;
	Vector p = r.o+(r.dir)*t;

	return p;
}

Vector Triangle::getNormalAtPoint(Vector& p) {
	Vector v = (p2-p1).cross(p3-p1);
	v.normalize();
	return v;
} 
