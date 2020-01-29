// Created by Melih Mete on 17.1.20
// BIL421 Computer Graphics - HW1

#include <GLUT/glut.h>
#include "gameelements.h"
#include "lane.h"

#pragma once
using namespace std;

User *user;
GameElements *game;
Lane *lanes;
GLuint ww = 500, wh = 600;
int totalScore = 0;
bool isGameEnded = false;
bool isGamePaused = false;

void bitMapString() {
   glColor3f(0.0f, 0.0f, 0.0f);
   char string[1024] = "Score :  ";
   char buffer[1024];
   sprintf(buffer, "%d", totalScore);
   strcat(string, buffer);
   int i=0;
   glRasterPos2f(10, 590);
   while (string[i] != '\0') {
      glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i]); ++i;
   } 
   glFlush();
}

void initializeLayout(void) {
   glViewport(0, 0, ww, wh);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, (GLdouble)ww, 0.0, (GLdouble)wh);

   glClearColor(0.0, 0.0, 0.0, 0.0);
}

void displayLayout(void) {

   glClear(GL_COLOR_BUFFER_BIT);

   lanes->drawBigLanes();
   lanes->drawSmallLanes();

   game->drawTrucks();
   game->drawCars();
   game->drawCoins();
   
   user->drawUser();

   bitMapString();

   if (game->isCrashed(*user)) {
      isGameEnded = true;
   } else if (game->isCollectedCoin(*user)){
      totalScore += 5;
   } else { }

   glFlush();
}

void mouseInput(int btn, int state, int x, int y) {
   if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
      exit(0); /*terminate the program through OpenGL */
}

void keyboardInput(unsigned char key, int x, int y)
{
   switch (key) 
   {
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

void moveUser(int key, int x, int y) {
   switch (key) {
      case GLUT_KEY_UP:
         user->goUp();

         if(!game->isCrashed(*user)) 
            ++totalScore;

         glutPostRedisplay();
         break;
      case GLUT_KEY_DOWN:
         user->goDown();

         if(!game->isCrashed(*user)) 
            ++totalScore;

         glutPostRedisplay();
         break;
      case GLUT_KEY_LEFT:
         user->turnLeft();
         glutPostRedisplay();
         break;
      case GLUT_KEY_RIGHT:
         user->turnRight();
         glutPostRedisplay();
         break;
      default:
         printf("Wrong button! \n");
   }
}

void initializeVehicles(int val) {
   game->generateVehicles();
   glutPostRedisplay();
   glutTimerFunc(500, initializeVehicles, 0);
}

void updateVehicles(int val) {
   game->passingVehicles();
   glutPostRedisplay();
   glutTimerFunc(100, updateVehicles, 2);
}

void initializeCoins(int val) {
   game->coinGeneration();
   glutPostRedisplay();
   glutTimerFunc(5000, initializeCoins, 1);
}

void destructCoins(int val) {
   game->coinDestruction();
   glutPostRedisplay();
   glutTimerFunc(10000, destructCoins, 3);
}

int main(int argc, char** argv) {

   user = new User();
   game = new GameElements();
   lanes = new Lane();

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(ww, wh);
   glutInitWindowPosition(0,0);
   glutCreateWindow("CrossLane");
   initializeLayout();
   glutMouseFunc(mouseInput);
   glutDisplayFunc(displayLayout);
   glutKeyboardFunc(keyboardInput);
   glutSpecialFunc(moveUser);
   glutTimerFunc(500, initializeVehicles, 0);
   glutTimerFunc(500, updateVehicles, 2);
   glutTimerFunc(500, initializeCoins, 1);
   glutTimerFunc(10000, destructCoins, 3);
   glutMainLoop();
}
