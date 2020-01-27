// Created by Melih Mete on 17.1.20
// BIL421 Computer Graphics - HW1

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <queue> 
#include <GLUT/glut.h>
#include <math.h>
#include <thread>
#include <unistd.h>
#include <random>
#include <algorithm>

//#include "truck.h"
//#include "car.h"
//#include "user.h"
#pragma once

#define PI 3.1415926535897932384626433832795
#define RADIUS 9
using namespace std;


float random_float(float min, float max) {
   float y = ((float)rand() / RAND_MAX) * (max - min) + min;
   printf("%lf\n",y);
	return y;
}

int random_integer(int min, int max) {
   return min + (rand() % static_cast<int>(max - min + 1));
}

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

typedef struct Truck {
   private:

      uint32_t tID;

      float wid;
      float hgt;

      float xCo;
      float yCo;
      float v;
      bool direction; // true = right --- false = left

public:

	Truck() {

	}

    Truck(float w, float h) {
        wid = w;
        hgt = h;
    }

    Truck(const Truck &otherTruck) {
        xCo = otherTruck.xCo;
        yCo = otherTruck.yCo;
        v = otherTruck.v;
        wid = otherTruck.wid;
        hgt = otherTruck.hgt;
        direction = otherTruck.direction;
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

    void setID(uint32_t id) {
       tID = id;
    }

    uint32_t getID() {
       return tID;
    }
};

struct Car {
   private:

      uint32_t cID;

      float wid;
      float hgt;

      float xCo;
      float yCo;
      float v;
      bool direction; // true = right --- false = left

public:
	Car() {

	}

    Car(float w, float h) {
        wid = w;
        hgt = h;
    }

    Car(const Car &otherCar) {
        xCo = otherCar.xCo;
        yCo = otherCar.yCo;
        v = otherCar.v;
        wid = otherCar.wid;
        hgt = otherCar.hgt;
        direction = otherCar.direction;
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

    void setID(uint32_t id) {
       cID = id;
    }

    uint32_t getID() {
       return cID;
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
unordered_map<uint32_t, Truck> *trucks;
unordered_map<uint32_t, Car> *cars;
vector<Coin> coins;
float deltaVelocity = 10.2;
User *user;
int totalScore = 0;
uint32_t UID = 0;

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
         
         if (user->getY() >= 580) {
            user->setY(600);
         } else {
            user->setY(user->getY() + 20);
         }
         user->setDirection(true);
         glutPostRedisplay();
         break;
      case GLUT_KEY_DOWN:
         
         if (user->getY() <= 20) {
            user->setY(0);
         } else {
            user->setY(user->getY() - 20);
         }
         user->setDirection(false);
         glutPostRedisplay();
         break;
      case GLUT_KEY_LEFT:
         if (user->getX() <= 10) {
            user->setX(0);
         } else {
            user->setX(user->getX() - 10);
         }
         glutPostRedisplay();
         break;
      case GLUT_KEY_RIGHT:
         if (user->getX() >= 490) {
            user->setX(500);
         } else {
            user->setX(user->getX() + 10);
         }
         glutPostRedisplay();
         break;
      default:
         exit(0);
   }
}

void myMouse(int btn, int state, int x, int y)
{
   if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
      exit(0); /*terminate the program through OpenGL */
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

void coinGeneration(int value) {
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
   glColor3f(1.0f, 1.0f, 0.0f);
   int v = value;
   for(auto &coin : coins) {
      glBegin(GL_POLYGON);
      for(double i = 0; i < 2 * PI; i += PI / 36) //<-- Change this Value
          glVertex3f(coin.getX() + cos(i) * RADIUS, coin.getY() + sin(i) * RADIUS, 0.0);
      glEnd();
   }
   glFlush();
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

   for(auto it = trucks->begin(); it != trucks->end(); it++) {
      int x = it->second.getX();
      int y = it->second.getY();

      glBegin(GL_POLYGON);
         glVertex2f(x - 18, y + 9);
         glVertex2f(x + 18, y + 9);
         glVertex2f(x + 18, y - 9);
         glVertex2f(x - 18, y - 9);
      glEnd();
   }

   for(auto it = cars->begin(); it != cars->end(); it++) {
      int x = it->second.getX();
      int y = it->second.getY();

      glBegin(GL_POLYGON);
         glVertex2f(x - 9, y + 9);
         glVertex2f(x + 9, y + 9);
         glVertex2f(x + 9, y - 9);
         glVertex2f(x - 9, y - 9);
      glEnd();
   }

   coinDrawing(0);

   glFlush();
}


void generateVehicles(int value) { 
   int yLine = random_integer(1, 30);
   if (yLine != 1 || yLine != 6 || yLine != 10 || yLine != 15 || yLine != 21 || yLine != 26 || yLine != 30 ) { 
      yLine = yLine * 10; - 5;
      int choice = 1 + (rand() % static_cast<int>(2 - 1 + 1));
      float velocity = random_float(0, 1);
      if (choice == 1) {
         Car car(18, 18);
         car.setX(0);
         car.setY(yLine);
         car.setVelocity(velocity);
         printf("Velocity : %lf\n", car.getVelocity());
         car.setID(++UID);
         cars->insert(make_pair(car.getID(), car));
      } else if (choice == 2) {
         Truck truck(18, 36);
         truck.setX(0);
         truck.setY(yLine);
         truck.setVelocity(velocity);
         truck.setID(++UID);
         trucks->insert(make_pair(truck.getID(), truck));
      } else {
         printf("No vehicle has been generated! \n");
      }  
   }
   glutPostRedisplay();
   glutTimerFunc(500, generateVehicles, 0);
}

void passingVehicles(int value) {

   vector<uint32_t> *idList = new vector<uint32_t>(cars->size());

   for(auto it = cars->begin(); it != cars->end(); it++) {
      float temp2 = it->second.getVelocity();
      float temp = (temp2 *10) + it->second.getX();
      it->second.setX(temp);
      if (it->second.getX() >= 500) {
         idList->push_back(it->first);
      }
   }

   for(auto key : *idList) {
      cars->erase(key);
   }

   for(auto it = trucks->begin(); it != trucks->end(); it++) {
      it->second.setX(it->second.getX() + it->second.getVelocity() * 10);
      if (it->second.getX() >= 500) {
         idList->push_back(it->first);
      }
   }

   for(auto key : *idList) {
      trucks->erase(key);
   }

   delete idList;
   
   glutPostRedisplay();
   glutTimerFunc(100, passingVehicles, 2);
}


int main(int argc, char** argv) {

   user = new User();
   trucks = new unordered_map<uint32_t, Truck>(10);
   cars = new unordered_map<uint32_t, Car>(10);

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(ww, wh);
   glutCreateWindow("CrossLane");
   myinit();
   glutMouseFunc(myMouse);
   glutDisplayFunc(myDisplay);
   glutKeyboardFunc(keyInput);
   glutSpecialFunc(moveUser);
   glutTimerFunc(500, generateVehicles, 0);
   glutTimerFunc(500, passingVehicles, 2);
   //glutTimerFunc(500, coinGeneration, 1);
   glutMainLoop();
}
