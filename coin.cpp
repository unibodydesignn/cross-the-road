#include "coin.h"


/*
 * Constructor of Coin class
 * Sets x and y coordinates default value to 0
 */
Coin::Coin() {
    xCo = 0;
    yCo = 0;
}

/**
 * Destructor of Coin class 
 */
Coin::~Coin() {

}

/**
 * @param int x - sets coins x coordinate to x
 * @return void
 */ 
void Coin::setX(int x) {
    xCo = x;
}

/**
 * @param none
 * @return -> X coordinate of coin object   
 */
int Coin::getX() {
    return xCo;
}

/**
 * @param integer y - sets coins y coordinate to y
 * @return -> none   
 */
void Coin::setY(int y) {
    yCo = y;
}

/**
 * @param none
 * @return -> y coordinate of coin
 * */
int Coin::getY() {
    return yCo;
}

