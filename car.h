#include <stdio.h> 
#include <iostream>

class Car {
private:

    uint32_t cID;

    float wid;
    float hgt;

    float xCo;
    float yCo;
    float v;
    bool direction; // true = right --- false = left

public:

    Car();
    Car(float w, float h);
    Car(const Car &otherCar);
    ~Car();

    void setCoordinate(float x, float y);
    void setVelocity(float vel);
    void setDirection(bool d);
    void setX(float x);
    float getX();
    float getVelocity();
    void setY(float y);
    float getY();
    void setID(uint32_t id);
    uint32_t getID();
};