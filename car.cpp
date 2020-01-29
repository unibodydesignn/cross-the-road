#include "car.h"

/**
 * 
 * Constructor of Car class
 * 
 * */
Car::Car() {

}

/**
 * @param float w, float h
 * 
 * Parametrized constructor of Car class
 * w -> width, h -> height
 * */
Car::Car(float w, float h) {
    wid = w;
    hgt = h;
}

/**
 * @param Car otherCar
 * 
 * Copy Constructor of Car class
 * Takes otherCar variables and copy them into this object
 * 
 * */
Car::Car(const Car &otherCar) {
    xCo = otherCar.xCo;
    yCo = otherCar.yCo;
    v = otherCar.v;
    wid = otherCar.wid;
    hgt = otherCar.hgt;
    direction = otherCar.direction;
    cID = otherCar.cID;
}

/**
 * 
 * Destructor of Car class
 * 
 * */
Car::~Car() {
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
void Car::setCoordinate(float x, float y) {
    xCo = x;
    yCo = y;
}

/**
 * @param float vel
 * @return void
 * 
 * Sets car velocity to given vel value
 * 
 * */
void Car::setVelocity(float vel) {
    v = vel;
} 

/**
 * @param bool d
 * @return void
 * 
 * Sets car direction to given d value
 * 
 * */
void Car::setDirection(bool d) {
    direction = d;
}


/**
 * @param float x
 * @return void
 * 
 * Sets car x coordinate to given x value
 * 
 * */
void Car::setX(float x) {
        xCo = x;
}

/**
 * @param none
 * @return float xCo
 * 
 * Returns x coordinate of car 
 * 
 * */
float Car::getX() {
    return xCo;
}

/**
 * @param float y
 * @return void
 * 
 * Sets car y coordinate to given y value
 * 
 * */
void Car::setY(float y) {
    yCo = y;
}

/**
 * @param none
 * @return float yCo
 * 
 * Returns y coordinate of car 
 * 
 * */
float Car::getY() {
    return yCo;
}

/**
 * @param none
 * @return float v
 * 
 * Returns velocity of car 
 * 
 * */
float Car::getVelocity() {
    return v;
}

/**
 * @param uint32_t id
 * @return void
 * 
 * Sets ID of car to given id val
 * 
 * */
void Car::setID(uint32_t id) {
    cID = id;
}


/**
 * @param none
 * @return uint32_t cID
 * 
 * Returns unique ID of the car
 * 
 * */
uint32_t Car::getID() {
    return cID;
}