#include <stdio.h> 
#include <iostream>

class Truck {

private:

    uint32_t tID;

    float wid;
    float hgt;

    float xCo;
    float yCo;
    
    float v;
    bool direction; // true = right --- false = left

public:
    Truck();
    Truck(float w, float h);
    Truck(const Truck &otherTruck);
    ~Truck();

    void setCoordinate(float x, float y);
    void setVelocity(float vel);
    void setDirection(bool d);
    bool getDirection();
    void setX(float x);
    float getX();
    void setY(float y);
    float getY();
    float getVelocity();
    void setID(uint32_t id);
    uint32_t getID();
};