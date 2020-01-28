#include "user.h"
#include <iostream>
using namespace std;

User::User() {
    xCo = 250;
    yCo = 0;
    direction = true;
}

// $(CC) $(CFLAGS) -c $< -o $@ -w 
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
