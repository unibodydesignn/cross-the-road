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
bool gameStatus = false;

void bitMapString() {
   if (isGamePaused == true) {
      glColor3f(0.0f, 0.0f, 0.0f);
      char string[1024] = "GAME PAUSED!";
      int i=0;
      glRasterPos2f(10, 590);
      while (string[i] != '\0') {
         glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i]); ++i;
      } 
      glFlush();
   } else if (isGameEnded == true) {
      glColor3f(0.0f, 0.0f, 0.0f);
      char string[1024] = "Game Over! Your Score :  ";
      char buffer[1024];
      sprintf(buffer, "%d", totalScore);
      strcat(string, buffer);
      int i=0;
      glRasterPos2f(10, 590);
      while (string[i] != '\0') {
         glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i]); ++i;
      } 
      glFlush();
   } else {
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
   
}

void gameState(int choice) {

   if (choice == 1 ) {             // Try again
      glClear(GL_COLOR_BUFFER_BIT);
   } else if (choice == 2) {      // exit game!
      exit(0);
   } else {
      printf("Something is not right! \n");
   }
}

void popupMenu() {
   glutCreateMenu(gameState);
	glutAddMenuEntry("Try Again!", 1);
   glutAddMenuEntry("Exit!", 2);
   glutPostRedisplay();
}

void removeMenu(int menuID) {
   glutDestroyMenu(menuID);
}

void initializeLayout(void) {
   glViewport(0, 0, ww, wh);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, (GLdouble)ww, 0.0, (GLdouble)wh);

   glClearColor(0.0, 0.0, 0.0, 0.0);
}

void displayLayout(void) {

   if (isGamePaused == true && isGameEnded == true ) {
      printf("Game paused or ended!\n");
   } else {
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
         popupMenu();
         totalScore += 5;
      } else { }
   }
   
   glFlush();
}

void mouseInput(int btn, int state, int x, int y) {
   if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
      exit(0); /*terminate the program through OpenGL */
   else if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
      isGamePaused = !isGamePaused;
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
   if (isGameEnded == true || isGamePaused == true) { 
      printf("Game paused! \n");
   } else {
      switch (key) {
         case GLUT_KEY_UP:
            user->goUp();

            if(!game->isCrashed(*user)) 
               ++totalScore;
            else
               isGameEnded = true;

            glutPostRedisplay();
            break;
         case GLUT_KEY_DOWN:
            user->goDown();

            if(!game->isCrashed(*user)) 
               ++totalScore;
            else
               isGameEnded = true;

            glutPostRedisplay();
            break;
         case GLUT_KEY_LEFT:
            user->turnLeft();

            if(game->isCrashed(*user))
               isGameEnded =true;

            glutPostRedisplay();
            break;
         case GLUT_KEY_RIGHT:
            user->turnRight();

            if(game->isCrashed(*user))
               isGameEnded = true;
               
            glutPostRedisplay();
            break;
         default:
            printf("Wrong button! \n");
      }
   }
}

void initializeVehicles(int val) {
   if (isGameEnded == true || isGamePaused == true) {
      printf("Game paused!\n");
   } else {
      game->generateVehicles();
   }
   glutPostRedisplay();
   glutTimerFunc(500, initializeVehicles, 0);
}

void updateVehicles(int val) {
   if (isGameEnded == true || isGamePaused == true) {
      printf("Game paused!\n");
   } else {
      game->passingVehicles();
   }
   glutPostRedisplay();
   glutTimerFunc(100, updateVehicles, 2);
}

void initializeCoins(int val) {
   if (isGameEnded == true || isGamePaused == true) {
      printf("Game paused!\n");
   } else {
      game->coinGeneration();
   }
   glutPostRedisplay();
   glutTimerFunc(5000, initializeCoins, 1);
}

void destructCoins(int val) {
   if (isGameEnded == true || isGamePaused == true) {
      printf("Game paused!\n");
   } else {
      game->coinDestruction();
   }
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
