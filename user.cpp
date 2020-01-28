#include "user.h"
#include <iostream>
#include <GLUT/glut.h>

using namespace std;

User::User() {
    xCo = 250;
    yCo = 10;
    direction = true;
}

User::~User() {
    xCo = 250;
    yCo = 0;
}

void User::setXY(float x, float y) {
    xCo = x;
    yCo = y;
}

void User::setX(float x) {
    xCo = x;
}

void User::setY(float y) {
    yCo = y;
}

float User::getX() {
    return xCo;
}

float User::getY() {
    return yCo;
}

bool User::getDirection() {
    return direction;
}

void User::setDirection(bool d) {
    direction = d;
}

void User::drawUser() {
    glColor3f(0.123f, 0.12, 1.0f);
    if (getDirection() == true) {
      glBegin(GL_TRIANGLES);
         glVertex2f(getX() -15, getY() -10);
         glVertex2f(getX() +15, getY() -10);
         glVertex2f(getX(), getY() + 10);
      glEnd();
   } else {
      glBegin(GL_TRIANGLES);
         glVertex2f(getX() -15, getY() + 10);
         glVertex2f(getX() +15, getY() + 10);
         glVertex2f(getX(), getY() - 10);
      glEnd();
   }
}
