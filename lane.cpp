#include "lane.h"
#include <stdio.h>


/**
 * Constructor of Lane class
 */
Lane::Lane() {
    printf("Constructed Lane!\n");
}

/**
 * Destructor of Lane class
 */
Lane::~Lane() {
    printf("Destructed Lane! \n");
}

/**
 * @param none 
 * @return void
 * 
 * This method draws walking road to screen with given coordinates
 **/
void Lane::drawBigLanes() {
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
}

/**
 * @param none
 * @return void
 * 
 * Draws small lanes in the layout.
 * Trucks, cars and coins will be generated in these lanes.
 * 
 * */
void Lane::drawSmallLanes() {
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
}