#include <stdio.h>
#include <algorithm>
using namespace std;

#include "vector.h"

enum tracerMode {
	ORTHO, PERSPECTIVE 
};

class Raytracer {
	//Camera parameters
	double znear,zfar;

	//Camera position
	Vector eye;

	//Window size
	double w,h;

	//Temporary sphere
	double sr;
	Vector pos;

	//Background colour
	double r,g,b,a;

	tracerMode currMode;

	public:
	Raytracer(double width, double height, double near,
		double far);
	Vector getColor(double px, double py);		
};
