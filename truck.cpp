#include "truck.h"

/**
 * 
 * Constructor of Truck class
 * 
 * */
Truck::Truck() {

}

/**
 * @param float w, float h
 * 
 * Parametrized constructor of Truck class
 * w -> width, h -> height
 * */
Truck::Truck(float w, float h) {
    wid = w;
    hgt = h;
}

/**
 * @param Truck otherTruck
 * 
 * Copy Constructor of Truck class
 * Takes otherTruck variables and copy them into this object
 * 
 * */
Truck::Truck(const Truck &otherTruck) {
    xCo = otherTruck.xCo;
    yCo = otherTruck.yCo;
    v = otherTruck.v;
    wid = otherTruck.wid;
    hgt = otherTruck.hgt;
    direction = otherTruck.direction;
    tID = otherTruck.tID;
}

/**
 * 
 * Destructor of Truck class
 * 
 * */
Truck::~Truck() {
    xCo = 0;
    yCo = 0;
}

/**
 * @param float x, float y
 * @return void
 * 
 * Set x and y coordinates of object to given x and y values
 * 
 **/
void Truck::setCoordinate(float x, float y) {
    xCo = x;
    yCo = y;
}

/**
 * @param float vel
 * @return void
 * 
 * Sets truck velocity to given vel value
 * 
 * */
void Truck::setVelocity(float vel) {
    v = vel;
} 

/**
 * @param bool d
 * @return void
 * 
 * Sets truck direction to given d value
 * 
 * */
void Truck::setDirection(bool d) {
    direction = d;
}

/**
 * @param none
 * @return bool direction
 * 
 * Returns direction of truck 
 * 
 * */
bool Truck::getDirection() {
    return direction;
}

/**
 * @param float x
 * @return void
 * 
 * Sets truck x coordinate to given x value
 * 
 * */
void Truck::setX(float x) {
    xCo = x;
}

/**
 * @param none
 * @return float xCo
 * 
 * Returns x coordinate of truck 
 * 
 * */
float Truck::getX() {
    return xCo;
}

/**
 * @param float y
 * @return void
 * 
 * Sets truck y coordinate to given y value
 * 
 * */
void Truck::setY(float y) {
    yCo = y;
}

/**
 * @param none
 * @return float yCo
 * 
 * Returns y coordinate of truck 
 * 
 * */
float Truck::getY() {
    return yCo;
}

/**
 * @param none
 * @return float v
 * 
 * Returns velocity of truck 
 * 
 * */
float Truck::getVelocity() {
    return v;
}

/**
 * @param uint32_t id
 * @return void
 * 
 * Sets ID of truck to given id val
 * 
 * */
void Truck::setID(uint32_t id) {
    tID = id;
}

/**
 * @param none
 * @return uint32_t cID
 * 
 * Returns unique ID of the truck
 * 
 * */
uint32_t Truck::getID() {
    return tID;
}