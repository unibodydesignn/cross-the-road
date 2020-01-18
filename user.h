#include <iostream> 

class User {

private:
    bool direction;
    float xCo;
    float yCo;

public:
    User() {
        xCo = 250;
        yCo = 0;
    }

    ~User() {
        xCo = 250;
        yCo = 0;
    }

    void setXY(float x, float y) {
        xCo = x;
        yCo = y;
    }

    void setX(float x) {
        xCo = x;
    }

    void setY(float y) {
        yCo = y;
    }

    float getX() {
        return xCo;
    }

    float getY() {
        return yCo;
    }
};