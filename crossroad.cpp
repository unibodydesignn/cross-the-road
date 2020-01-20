// Created by Melih Mete on 17.1.20
// BIL421 Computer Graphics - HW1

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue> 
#include <GLUT/glut.h>
#include <math.h>
#include <random>
//#include "truck.h"
//#include "car.h"
//#include "user.h"
#pragma once

#define PI 3.1415926535897932384626433832795
#define RADIUS 5
using namespace std;

struct User {

   bool direction;
   float xCo;
   float yCo;

   User() {
      xCo = 250;
      yCo = 0;
      direction = true;
      printf("User has been constructed;\n");
   }

   ~User() {
      xCo = 250;
      yCo = 0;
   }

   void setXY(float x, float y) {
      xCo = x;
      yCo = y;
   }

   void setX(float x) {
      xCo = x;
   }

   void setY(float y) {
      yCo = y;
   }

   float getX() {
      return xCo;
   }

   float getY() {
      return yCo;
   }

   bool getDirection() {
      return direction;
   }

   void setDirection(bool d) {
      direction = d;
   }
};

struct Truck {
   private:

      float wid;
      float hgt;

      float xCo;
      float yCo;
      float v;
      bool direction; // true = right --- false = left

public:
    Truck(float w, float h) {
        wid = w;
        hgt = h;
    }

    Truck(const Truck &otherTruck) {
        xCo = otherTruck.xCo;
        yCo = otherTruck.yCo;
    }

    ~Truck() {
        xCo = 0;
        yCo = 0;
    }

    void setCoordinate(float x, float y) {
        xCo = x;
        yCo = y;
    }

    void setVelocity(float vel) {
        v = vel;
    } 

    void setDirection(bool d) {
        direction = d;
    }

    void setX(float x) {
        xCo = x;
    }

    float getX() {
        return xCo;
    }

   void setY(float y) {
       yCo = y;
    }

   float getY() {
      return yCo;
   }

    float getVelocity() {
        return v;
    }
};

struct Car {
   private:

      float wid;
      float hgt;

      float xCo;
      float yCo;
      float v;
      bool direction; // true = right --- false = left

public:
    Car(float w, float h) {
        wid = w;
        hgt = h;
    }

    Car(const Car &otherTruck) {
        xCo = otherTruck.xCo;
        yCo = otherTruck.yCo;
    }

    ~Car() {
        xCo = 0;
        yCo = 0;
    }

    void setCoordinate(float x, float y) {
        xCo = x;
        yCo = y;
    }

    void setVelocity(float vel) {
        v = vel;
    } 

    void setDirection(bool d) {
        direction = d;
    }

    void setX(float x) {
        xCo = x;
    }

    float getX() {
        return xCo;
    }

   void setY(float y) {
       yCo = y;
    }

   float getY() {
      return yCo;
   }

    float getVelocity() {
        return v;
    }
};

struct Coin {

private:
   int xCo;
   int yCo;
public:
   void setX(int x) {
      xCo = x;
   }

   int getX() {
      return xCo;
   }

   void setY(int y) {
      yCo = y;
   }

   int getY() {
      return yCo;
   }
};


GLsizei wh = 600, ww = 500; /* initial window size */
GLfloat size = 3.0;   /* half side length of square */
queue<Truck> *trucks;
queue<Car> *cars;
vector<Coin> coins;
float deltaVelocity = 10.2;
User *user;
int totalScore = 0;
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

   glClearColor(0.0, 0.0, 0.0, 0.0);
}

void moveUser(int key, int x, int y) {
   switch (key) {
      case GLUT_KEY_UP:
         glutPostRedisplay();
         if (user->getY() >= 580) {
            user->setY(600);
         } else {
            user->setY(user->getY() + 20);
         }
         user->setDirection(true);
         printf("UP User location %f %f \n", user->getX(), user->getY());
         break;
      case GLUT_KEY_DOWN:
         glutPostRedisplay();
         if (user->getY() <= 20) {
            user->setY(0);
         } else {
            user->setY(user->getY() - 20);
         }
         user->setDirection(false);
         printf("DOWN User location %f %f \n", user->getX(), user->getY());
         break;
      case GLUT_KEY_LEFT:
      glutPostRedisplay();
         if (user->getX() <= 10) {
            user->setX(0);
         } else {
            user->setX(user->getX() - 10);
         }
         
         printf("LEFT User location %f %f \n", user->getX(), user->getY());
         break;
      case GLUT_KEY_RIGHT:
      glutPostRedisplay();
         printf("Tusa basildi");
         if (user->getX() >= 490) {
            user->setX(500);
         } else {
            user->setX(user->getX() + 10);
         }
         
         printf("RIGHT User location %f %f \n", user->getX(), user->getY());
         break;
      default:
         exit(0);
   }
   //glutPostRedisplay();
   //glFlush();
}

void myMouse(int btn, int state, int x, int y)
{
   if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
      exit(0); /*terminate the program through OpenGL */
}

void passingTrucks() {

   

}

void passingCars() {

}

bool checkCarCollision(Truck &otherTruck) {
   bool collisionX = false;
   bool collisionY = false;

   collisionX = user->getX() >= otherTruck.getX() & otherTruck.getX() >= user->getX();
   collisionY = user->getY() >= otherTruck.getY() & otherTruck.getY() >= user->getY();
 
   return collisionX & collisionY;
}

bool checkTruckCollision(Car &otherCar) {

   bool collisionX = false;
   bool collisionY = false;

   collisionX = user->getX() >= otherCar.getX() & otherCar.getX() >= user->getX();
   collisionY = user->getY() >= otherCar.getY() & otherCar.getY() >= user->getY();
 
   return collisionX & collisionY;

}

bool checkCoinCollision(Coin &coin) {

   bool collisionX = false;
   bool collisionY = false;

   collisionX = user->getX() >= coin.getX() & coin.getX() >= user->getX();
   collisionY = user->getY() >= coin.getY() & coin.getY() >= user->getY();
 
   return collisionX & collisionY;
}

void coinGeneration() {
   coins.clear();
   glColor3f(1.0f, 1.0f, 0.0f);
   for(int c = 0; c < 10; c++) {
      int x = 10 + (rand() % static_cast<int>(500 - 10 + 1));
      int y = 10 + (rand() % static_cast<int>(600 - 10 + 1));
      Coin coin;
      coin.setX(x);
      coin.setY(y);
      coins.push_back(coin);
      if (c == 9) {
         break;
      }
   }
}

void coinDrawing(int value) {
   
   int v = value;
   coinGeneration();
   for(auto &coin : coins) {
      glBegin(GL_POLYGON);
      for(double i = 0; i < 2 * PI; i += PI / 36) //<-- Change this Value
          glVertex3f(coin.getX() + cos(i) * RADIUS, coin.getY() + sin(i) * RADIUS, 0.0);
      glEnd();
      glFlush();
   }
   
}

void keyInput(unsigned char key, int x, int y)
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

void myDisplay(void)
{   
   glClear(GL_COLOR_BUFFER_BIT);
   //glLoadIdentity();
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

   //User location 
   glColor3f(0.123f, 0.12, 1.0f);
   if (user->getDirection() == true) {
      glBegin(GL_TRIANGLES);
         glVertex2f(user->getX() -15, user->getY());
         glVertex2f(user->getX() +15, user->getY());
         glVertex2f(user->getX(), user->getY() + 19);
      glEnd();
   } else {
      glBegin(GL_TRIANGLES);
         glVertex2f(user->getX() -15, user->getY());
         glVertex2f(user->getX() +15, user->getY());
         glVertex2f(user->getX(), user->getY() - 19);
      glEnd();
   }

   glFlush();
}


int main(int argc, char** argv) {

   user = new User();
   cars = new queue<Car>();
   trucks = new queue<Truck>();
   //coins = new vector<Coin>(10);

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(ww, wh);
   glutCreateWindow("CrossLane");
   myinit();
   glutMouseFunc(myMouse);
   glutDisplayFunc(myDisplay);
   glutKeyboardFunc(keyInput);
   glutSpecialFunc(moveUser);
   glutTimerFunc(1000, coinDrawing, 0);
   glutMainLoop();
}
