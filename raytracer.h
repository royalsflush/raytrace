#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

#include "vector.h"
#include "node.h" 
#include "light.h"

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

	//Light vector
	vector<Light*> lights;

	//Rays per pixel
	int raysPP; 

	public:
	Raytracer(double width, double height, double near,
		double far);
	Vector getPixelColor(int px, int py);
	Vector getColor(double px, double py);
	void setBackground(float r, float g, float g, 
		float a); 
};
