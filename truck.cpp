#include "truck.h"

Truck::Truck() {

}

Truck::Truck(float w, float h) {
    wid = w;
    hgt = h;
}

Truck::Truck(const Truck &otherTruck) {
    xCo = otherTruck.xCo;
    yCo = otherTruck.yCo;
    v = otherTruck.v;
    wid = otherTruck.wid;
    hgt = otherTruck.hgt;
    direction = otherTruck.direction;
    tID = otherTruck.tID;
}

Truck::~Truck() {
    xCo = 0;
    yCo = 0;
}

void Truck::setCoordinate(float x, float y) {
    xCo = x;
    yCo = y;
}

void Truck::setVelocity(float vel) {
    v = vel;
} 

void Truck::setDirection(bool d) {
    direction = d;
}

void Truck::setX(float x) {
    xCo = x;
}

float Truck::getX() {
    return xCo;
}

void Truck::setY(float y) {
    yCo = y;
}

float Truck::getY() {
    return yCo;
}

float Truck::getVelocity() {
    return v;
}

void Truck::setID(uint32_t id) {
    tID = id;
}

uint32_t Truck::getID() {
    return tID;
}