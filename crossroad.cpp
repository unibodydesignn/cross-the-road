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

/**
 * @param none
 * @return void
 * 
 * Displays string on the top left corner of screen
 * 
 * */
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

/**
 * @param int choice
 * @return void
 * 
 * By choice, menu will decide what to do!
 * 
 * */
void gameState(int choice) {

   if (choice == 1 ) {             // Try again
      glClear(GL_COLOR_BUFFER_BIT);
   } else if (choice == 2) {      // exit game!
      exit(0);
   } else {
      printf("Something is not right! \n");
   }
}

/**
 * @param none
 * @return void
 * 
 * Creates pop-up menu
 * 
 * */
void popupMenu() {
   glutCreateMenu(gameState);
	glutAddMenuEntry("Try Again!", 1);
   glutAddMenuEntry("Exit!", 2);
   glutPostRedisplay();
}

/**
 * @param int menuID
 * @return void
 * 
 * Destroys menu with the given menuID
 * 
 * */
void removeMenu(int menuID) {
   glutDestroyMenu(menuID);
}

/**
 * @param void
 * @return void
 * 
 * Layout initialize function for OpenGL
 * 
 * */
void initializeLayout(void) {
   glViewport(0, 0, ww, wh);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, (GLdouble)ww, 0.0, (GLdouble)wh);

   glClearColor(0.0, 0.0, 0.0, 0.0);
}

/**
 * @param void
 * @return void
 * 
 * Display initialization function
 * Takes game objects and draws them to screen
 * If game paused or over, function will stop running
 * */
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

/**
 * @param int btn, int state, int x, int y
 * @return void
 * 
 * Takes mouse input from mouse register
 * If left button clicked game pauses or resumes
 * If middle button is pressed, exits program
 * 
 * */
void mouseInput(int btn, int state, int x, int y) {
   if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
      exit(0); /*terminate the program through OpenGL */
   else if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
      isGamePaused = !isGamePaused;
}

/**
 * @param unsigned char key, int x, int y
 * @return void
 * 
 * If key is 27, quits.
 * 
 * */
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

/**
 * @param iny key, int x, int y
 * @return void
 * 
 * Special function for moving user
 * If key is up, user moves to upper lane.
 * If key is down, user moves to lower lane.
 * If key is left, user moves slightly to left.
 * If key is right, user moves slightly to right.
 * 
 * Checks collision for every movement.
 * If collision occurs with vehicles, game is over
 * If collision occurs with coins, coin will be collected and +5 points.
 * Game continues till user crashes.
 * 
 * */
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

/**
 * @param int val
 * @return void
 * 
 * If game is not ended or paused, function continues to generate vehicles 
 * 
 * */
void initializeVehicles(int val) {
   if (isGameEnded == true || isGamePaused == true) {
      printf("Game paused!\n");
   } else {
      game->generateVehicles();
   }
   glutPostRedisplay();
   glutTimerFunc(150, initializeVehicles, 0);
}

/**
 * @param int val
 * @return void
 * 
 * If game is not ended or paused, function continues to update vehicle position 
 * 
 * */
void updateVehicles(int val) {
   if (isGameEnded == true || isGamePaused == true) {
      //printf("Game paused!\n");
   } else {
      game->passingVehicles();
   }
   glutPostRedisplay();
   glutTimerFunc(50, updateVehicles, 2);
}

/**
 * @param int val
 * @return void
 * 
 * If game is not ended or paused, function continues to generate coins
 * Generation of coins happens every 5000 ms. 
 * 
 * */
void initializeCoins(int val) {
   if (isGameEnded == true || isGamePaused == true) {
      //printf("Game paused!\n");
   } else {
      game->coinGeneration();
   }
   glutPostRedisplay();
   glutTimerFunc(5000, initializeCoins, 1);
}

/**
 * @param int val
 * @return void
 * 
 * If game is not ended or paused, function continues to destroy coins
 * Destroying operations processed every 10000 ms.
 * 
 * */
void destructCoins(int val) {
   if (isGameEnded == true || isGamePaused == true) {
      //printf("Game paused!\n");
   } else {
      game->coinDestruction();
   }
   glutPostRedisplay();
   glutTimerFunc(10000, destructCoins, 3);
}


/**
 * 
 * This is where magic happens.
 * Magic of glutMainLoop.
 * 
 * */
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
   glutTimerFunc(200, initializeVehicles, 0);
   glutTimerFunc(300, updateVehicles, 2);
   glutTimerFunc(500, initializeCoins, 1);
   glutTimerFunc(10000, destructCoins, 3);
   glutMainLoop();
}
