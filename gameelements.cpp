#include "gameelements.h"

GameElements::GameElements() {
    trucks = new unordered_map<uint32_t, Truck>(10);
    cars = new unordered_map<uint32_t, Car>(10);
    coins = new vector<Coin>(10);
    randomGenerator = new Random();
    UID = 0;
}

GameElements::~GameElements() {
    delete trucks;
    delete cars;
    delete coins;
}

void GameElements::generateVehicles() {

    int yLine = randomGenerator->random_integer(1, 29);   
    if (yLine == 0 || yLine == 5 || yLine == 9 || yLine == 14 || yLine == 20 || yLine == 25 || yLine == 30) { 
        //printf(".... %d \n", yLine);
    } else {
        yLine = yLine * 20 + 10;
        int choice = 1 + (rand() % static_cast<int>(2 - 1 + 1));
        float velocity = randomGenerator->random_float(0.5, 1);
        if (choice == 1) {
            Car car(18, 18);
            car.setX(0);
            car.setY(yLine);
            car.setVelocity(velocity);
            car.setID(++UID);
            cars->insert(make_pair(car.getID(), car));
        } else if (choice == 2) {
            Truck truck(18, 36);
            truck.setX(0);
            truck.setY(yLine);
            truck.setVelocity(velocity);
            truck.setID(++UID);
            trucks->insert(make_pair(truck.getID(), truck));
        } else {
            printf("No vehicle has been generated! \n");
        } 
    }
}

void GameElements::coinGeneration() {
    coins->clear();
    glColor3f(1.0f, 1.0f, 0.0f);
    for(int c = 0; c < 10; c++) {
        int x = 10 + (rand() % static_cast<int>(500 - 10 + 1));
      int y = 10 + (rand() % static_cast<int>(30 - 0 + 1));
      y = y * 20 + 10;
      Coin coin;
      coin.setX(x);
      coin.setY(y);
      coins->push_back(coin);
      if (c == 9) {
         break;
      }
   }
}

void GameElements::coinDestruction() {
    coins->clear();
}

void GameElements::drawTrucks() {
    glColor3f(0.534, 0.653, 0.78);
    for(auto it = trucks->begin(); it != trucks->end(); it++) {
      int x = it->second.getX();
      int y = it->second.getY();

      glBegin(GL_POLYGON);
         glVertex2f(x - 20, y + 10);
         glVertex2f(x + 20, y + 10);
         glVertex2f(x + 20, y - 10);
         glVertex2f(x - 20, y - 10);
      glEnd();
    }
}

void GameElements::drawCars() {
    glColor3f(0.87, 0.53, 0.23);
    for(auto it = cars->begin(); it != cars->end(); it++) {
        int x = it->second.getX();
        int y = it->second.getY();

        glBegin(GL_POLYGON);
            glVertex2f(x - 10, y + 10);
            glVertex2f(x + 10, y + 10);
            glVertex2f(x + 10, y - 10);
            glVertex2f(x - 10, y - 10);
        glEnd();
    }
}

void GameElements::drawCoins() {
    glColor3f(1.0f, 1.0f, 0.0f);
    for(auto &coin : *coins) {
      glBegin(GL_POLYGON);
      for(double i = 0; i < 2 * PI; i += PI / 36) //<-- Change this Value
          glVertex3f(coin.getX() + cos(i) * RADIUS, coin.getY() + sin(i) * RADIUS, 0.0);
        glEnd();
    }
}


void GameElements::passingVehicles() {
    vector<uint32_t> *idList = new vector<uint32_t>(cars->size());

    for(auto it = cars->begin(); it != cars->end(); it++) {
        float temp2 = it->second.getVelocity();
        float temp = (temp2 *10) + it->second.getX();
        it->second.setX(temp);
        if (it->second.getX() >= 500) {
            idList->push_back(it->first);
        }
    }

    for(auto key : *idList) {
        cars->erase(key);
    }

    for(auto it = trucks->begin(); it != trucks->end(); it++) {
        it->second.setX(it->second.getX() + it->second.getVelocity() * 10);
        if (it->second.getX() >= 500) {
            idList->push_back(it->first);
        }
    }

    for(auto key : *idList) {
        trucks->erase(key);
    }

    delete idList;
}

bool GameElements::checkTruckCollision(Truck &otherTruck, User &user) {
    bool collisionXLeft = false;
    bool collisionXRight = false;
    bool collisionY = false;

    collisionXLeft = user.getX() + 10 >= otherTruck.getX() -10 && user.getX() -10 <= otherTruck.getX() -10;
    collisionXRight = user.getX() -10 <= otherTruck.getX() + 10 && user.getX() - 10 >= otherTruck.getX() + 10;
    collisionY = user.getY() >= otherTruck.getY() && otherTruck.getY() >= user.getY();

    return (collisionXLeft || collisionXRight) && collisionY;
}

bool GameElements::checkCarCollision(Car &otherCar, User &user) {
    bool collisionXLeft = false;
    bool collisionXRight = false;
    bool collisionY = false;

    collisionXLeft = user.getX() + 10 >= otherCar.getX() -10 && user.getX() -10 <= otherCar.getX() -10;
    collisionXRight = user.getX() -10 <= otherCar.getX() + 10 && user.getX() - 10 >= otherCar.getX() + 10;
    collisionY = user.getY() >= otherCar.getY() && otherCar.getY() >= user.getY();

    return (collisionXLeft || collisionXRight) && collisionY;

}

bool GameElements::checkCoinCollision(Coin &coin, User &user) {
    bool collisionXLeft = false;
    bool collisionXRight = false;
    bool collisionY = false;

    collisionXLeft = user.getX() + 10 >= coin.getX()  && user.getX() <= coin.getX();
    collisionXRight = user.getX() -10 <= coin.getX()  && user.getX()  >= coin.getX();
    collisionY = user.getY() >= coin.getY() && coin.getY() >= user.getY();

    return (collisionXLeft || collisionXRight) && collisionY;
}

bool GameElements::isCrashed(User &user) {
    
    for(auto it = trucks->begin(); it != trucks->end(); it++) { 
      if (checkTruckCollision(it->second, user))
         return true;
   }

   for(auto it = cars->begin(); it != cars->end(); it++) { 
      if (checkCarCollision(it->second, user)) 
         return true;
   }

   return false;
}

bool GameElements::isCollectedCoin(User &user) {
    bool collected = false;
    for(int i = 0; i < coins->size(); i++) {
        if(checkCoinCollision(coins->at(i), user)) {
            coins->erase(coins->begin() + i);
            return true;
        }
   }
   return collected;
}