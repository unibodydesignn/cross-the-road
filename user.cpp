#include "user.h"
#include <iostream>
#include <GLUT/glut.h>

using namespace std;

/**
 * Constructor for User class
 * */
User::User() {
    xCo = 250;
    yCo = 10;
    direction = true;
}

/**
 * Destructor for User class
 * */
User::~User() {
    xCo = 250;
    yCo = 0;
}

/**
 * @param float x, float y
 * @return void
 * 
 * Sets given x and y values to users x and y coordinates
 * 
 * */
void User::setXY(float x, float y) {
    xCo = x;
    yCo = y;
}

/**
 * @param float x
 * @return void
 * 
 * Sets given x value to users x coordinate
 * 
 * */
void User::setX(float x) {
    xCo = x;
}

/**
 * @param float y
 * @return void
 * 
 * Sets given y value to users y coordinate
 * 
 * */
void User::setY(float y) {
    yCo = y;
}

/**
 * @param none
 * @return float xCo
 * 
 * Returns x coordinate of user
 * 
 * */
float User::getX() {
    return xCo;
}

/**
 * @param none
 * @return float yCo
 * 
 * Returns y coordinate of user
 * 
 * */
float User::getY() {
    return yCo;
}

/**
 * @param none
 * @return bool direction
 * 
 * Returns direction (upwards or downwards) of user
 * 
 * */
bool User::getDirection() {
    return direction;
}

/**
 * @param bool d
 * @return void
 * 
 * Sets d value to users direction value
 * 
 * */
void User::setDirection(bool d) {
    direction = d;
}

/**
 * @param none
 * @return void
 * 
 * Draws user to screen by its coordinates
 * If direction is true, draws it directed to up
 * If direction is false, draws it directo to down
 * 
 * */
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

/**
 * @param none
 * @return void
 * 
 * Increments Y coordinate of user
 * If user is on top, user is directed to down
 * 
 * */
void User::goUp() {
    if (getY() >= 580) {
        setY(590);
        setDirection(false);
    } else {
        setY(getY() + 20);
        setDirection(true);
    }
}

/**
 * @param none
 * @return void
 * 
 * Decrements Y coordinate of user
 * If user is on bottom, user is directed to up
 * 
 * */
void User::goDown() {
    if (getY() <= 20) {
        setY(10);
        setDirection(true);
    } else {
        setY(getY() - 20);
        setDirection(false);
    }
}

/**
 * @param none
 * @return void
 * 
 * Decrements X coordinate of user
 * 
 * */
void User::turnLeft() {
    if (getX() <= 10) {
        setX(0);
    } else {
        setX(getX() - 10);
    }
}

/**
 * @param none
 * @return void
 * 
 * Increments X coordinate of user
 * 
 * */
void User::turnRight() {
    if (getX() >= 490) {
        setX(500);
    } else {
        setX(getX() + 10);
    }
}
