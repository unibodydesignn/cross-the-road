// Created by Melih Mete on 17.1.20
// BIL421 Computer Graphics - HW1

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue> 
#include <GLUT/glut.h>

#include "truck.h"
#include "car.h"
#include "user.h"

#pragma once
using namespace std;
/* globals */

GLsizei wh = 600, ww = 500; /* initial window size */
GLfloat size = 3.0;   /* half side length of square */
vector<Truck> trucks;
vector<Car> cars;
User user();

float deltaVelocity = 10.2;

/* rehaping routine called whenever window is resized
or moved */

void myReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	ww = w;
	wh = h;
}

void myinit(void)
{
	glViewport(0, 0, ww, wh);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)ww, 0.0, (GLdouble)wh);

	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void myKeyboard(unsigned char key, int x, int y)
{
	if ((key == 'Q') || (key == 'q'))
		exit(0);
}

void myMouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		exit(0); /*terminate the program through OpenGL */
}

void createPassingVehicles(int time) {


   glutPostRedisplay();

}

void myDisplay(void)
{   
   glColor3f(1.0, 1.0, 1.0f);

   //Bottom lane
   glBegin(GL_POLYGON);
      glVertex2f(0.0f, 0.0f);
      glVertex2f(500.f, 0.0f);
      glVertex2f(500.f, 20.f);
      glVertex2f(0.0f, 20.f);
   glEnd(); 
   
   glBegin(GL_POLYGON);
      glVertex2f(0.0f, 100.0f);
      glVertex2f(500.f, 100.0f);
      glVertex2f(500.f, 120.f);
      glVertex2f(0.0f, 120.f);
   glEnd();

   glBegin(GL_POLYGON);
      glVertex2f(0.0f, 180.0f);
      glVertex2f(500.f, 180.0f);
      glVertex2f(500.f, 200.f);
      glVertex2f(0.0f, 200.f);
   glEnd();

   glBegin(GL_POLYGON);
      glVertex2f(0.0f, 280.0f);
      glVertex2f(500.f, 280.0f);
      glVertex2f(500.f, 300.f);
      glVertex2f(0.0f, 300.f);
   glEnd();

   glBegin(GL_POLYGON);
      glVertex2f(0.0f, 400.0f);
      glVertex2f(500.f, 400.0f);
      glVertex2f(500.f, 420.f);
      glVertex2f(0.0f, 420.f);
   glEnd();

   glBegin(GL_POLYGON);
      glVertex2f(0.0f, 500.0f);
      glVertex2f(500.f, 500.0f);
      glVertex2f(500.f, 520.f);
      glVertex2f(0.0f, 520.f);
   glEnd();

   // Top lane
   glBegin(GL_POLYGON);
      glVertex2f(0.0f, 580.0f);
      glVertex2f(500.f, 580.0f);
      glVertex2f(500.f, 600.f);
      glVertex2f(0.0f, 600.f);
   glEnd();
  
   // Draws the road lane one by one
   glColor3f(1.0f, 1.0f, 1.0f);
   for(int y = 40; y < 600; y += 20) {
      for(int x = 0; x < 500; x += 20) {
         glBegin(GL_LINES);
            glVertex2f(x, y);
            glVertex2f(x + 10, y);
         glEnd();
      }
   }

   glFlush();
}


int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww, wh);
	glutCreateWindow("CrossLane");
	myinit();
	glutReshapeFunc(myReshape);
	glutMouseFunc(myMouse);
	//glutMotionFunc(makeSquare);
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(myKeyboard);
   glutTimerFunc(200, createPassingVehicles, 0);
	//srand(time(NULL));
	glutMainLoop();
}
