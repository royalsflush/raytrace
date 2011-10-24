#include <stdio.h>
#include <algorithm>
using namespace std;

#include "vector.h"
#include "node.h" 

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

	//Background colour
	Vector bgVec;

	//Projection mode
	tracerMode currMode;

	//Scene tree
	Node* root;

	public:
	Raytracer(double width, double height, double near,
		double far);
	Vector getColor(double px, double py);		
};
