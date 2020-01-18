#include <stdio.h> 
#include <iostream>

class Truck {

private:

    float wid;
    float hgt;

    float xCo;
    float yCo;
    float v;
    bool direction; // true = right --- false = left

public:
    Truck(float w, float h) {
        wid = w;
        hgt = h;
    }

    Truck(const Truck &otherTruck) {
        xCo = otherTruck.xCo;
        yCo = otherTruck.yCo;
    }

    ~Truck() {
        xCo = 0;
        yCo = 0;
    }

    void setCoordinate(float x, float y) {
        xCo = x;
        yCo = y;
    }

    void setVelocity(float vel) {
        v = vel;
    } 

    void setDirection(bool d) {
        direction = d;
    }

    void setX(float x) {
        xCo = x;
    }

    float getX() {
        return xCo;
    }

    float getVelocity() {
        return v;
    }
};