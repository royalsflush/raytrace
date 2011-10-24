#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "raytracer.h"
#include "vector.h"

#define WIN_W 1024
#define WIN_H 768

Raytracer* r;

void initRender();
void init();
void handleKeyPress(unsigned char k, int x, int y);
void handleResize(int w, int h);
void render();

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WIN_W, WIN_H);

	glutCreateWindow("First try: raytracer");
	init();

	glutKeyboardFunc(handleKeyPress);
	glutDisplayFunc(render);
	glutReshapeFunc(handleResize);

	glutMainLoop();
		
	return 0;
}

void init() {
	r = new Raytracer(WIN_W, WIN_H,
			50.0,1000.0);
	initRender();
}

void initRender() {
	glClearColor(0.0,0.0,0.0,0.0);
	r->setBackground(0.0,0.0,0.0,0.0);
	
	glClear(GL_COLOR_BUFFER_BIT);

	glDisable(GL_DEPTH);
	glEnable(GL_COLOR);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WIN_W, 0.0, WIN_H);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
	glViewport(0, 0, WIN_W, WIN_H);
}

void handleKeyPress(unsigned char k, int x, int y) {
	if (k==27) exit(0);
	if (k=='q') exit(0);
}

void handleResize(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,w,0.0,h);

	glMatrixMode(GL_MODELVIEW);	
	glViewport(0,0,w,h);

}

void render() {
	glClear(GL_COLOR_BUFFER_BIT);

	for (int x=0; x<WIN_W; x++) {
		for (int y=0; y<WIN_H; y++) {
			Vector col = r->getPixelColor(x,y);
			glColor3f(col.x,col.y,col.z);
			
			glBegin(GL_POINTS);
				glVertex2i(x,y);
			glEnd();
		}
	}

	glFlush();
	glutSwapBuffers();
}
