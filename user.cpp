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

void User::goUp() {
    if (getY() >= 580) {
        setY(590);
        setDirection(false);
    } else {
        setY(getY() + 20);
        setDirection(true);
    }
}

void User::goDown() {
    if (getY() <= 20) {
        setY(10);
        setDirection(true);
    } else {
        setY(getY() - 20);
        setDirection(false);
    }
}

void User::turnLeft() {
    if (getX() <= 10) {
        setX(0);
    } else {
        setX(getX() - 10);
    }
}

void User::turnRight() {
    if (getX() >= 490) {
        setX(500);
    } else {
        setX(getX() + 10);
    }
}
