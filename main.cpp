#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#define WIN_W 1024
#define WIN_H 768

void initRender();
void handleKeyPress(unsigned char k, int x, int y);
void handleResize(int w, int h);
void render();

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WIN_W, WIN_H);

	glutCreateWindow("First try: raytracer");
	initRender();

	glutKeyboardFunc(handleKeyPress);
	glutDisplayFunc(render);
	glutReshapeFunc(handleResize);

	glutMainLoop();
		
	return 0;
}

void initRender() {
	glClearColor(0.0,0.0,0.0,0.0);
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
	glColor4f(1.0,0.0,0.0,0.0);

	glBegin(GL_QUADS);
		glVertex2i(100,100);
		glVertex2i(200,100);
		glVertex2i(200,200);
		glVertex2i(100,200);
	glEnd();

	glFlush();
	glutSwapBuffers();
}
