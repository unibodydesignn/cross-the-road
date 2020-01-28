#include "car.h"

Car::Car() {

}

Car::Car(float w, float h) {
    wid = w;
    hgt = h;
}

Car::Car(const Car &otherCar) {
    xCo = otherCar.xCo;
    yCo = otherCar.yCo;
    v = otherCar.v;
    wid = otherCar.wid;
    hgt = otherCar.hgt;
    direction = otherCar.direction;
    cID = otherCar.cID;
}

Car::~Car() {
    xCo = 0;
    yCo = 0;
}

void Car::setCoordinate(float x, float y) {
    xCo = x;
    yCo = y;
}

void Car::setVelocity(float vel) {
    v = vel;
} 

void Car::setDirection(bool d) {
    direction = d;
}

void Car::setX(float x) {
        xCo = x;
}

float Car::getX() {
    return xCo;
}

void Car::setY(float y) {
    yCo = y;
}

float Car::getY() {
    return yCo;
}

float Car::getVelocity() {
    return v;
}

void Car::setID(uint32_t id) {
    cID = id;
}

uint32_t Car::getID() {
    return cID;
}