#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <GLUT/glut.h>

#include "coin.h"
#include "truck.h"
#include "car.h"
#include "user.h"
#include "random.h"

#pragma once

#define PI 3.1415926535897932384626433832795
#define RADIUS 10

using namespace std;

class GameElements {

private:
    vector<Coin> *coins;
    unordered_map<uint32_t, Truck> *trucks;
    unordered_map<uint32_t, Car> *cars;
    
    Random *randomGenerator;
    uint32_t UID;

public:
    GameElements();
    ~GameElements();

    void drawTrucks();
    void drawCars();
    void drawCoins();

    void generateVehicles();
    void passingVehicles();
    void coinGeneration();
    void coinDestruction();

    bool checkTruckCollision(Truck &otherTruck, User &user);
    bool checkCarCollision(Car &otherCar, User &user);
    bool isCrashed(User &user);

    bool checkCoinCollision(Coin &coin, User &user);
    bool isCollectedCoin(User &user);

};