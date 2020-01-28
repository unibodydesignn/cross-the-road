#include "coin.h"

Coin::Coin() {
    xCo = 0;
    yCo = 0;
}

Coin::~Coin() {

}

void Coin::setX(int x) {
    xCo = x;
}

int Coin::getX() {
    return xCo;
}

void Coin::setY(int y) {
    yCo = y;
}

int Coin::getY() {
    return yCo;
}

