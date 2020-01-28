#include <iostream> 

using namespace std;

class User {

private:
    bool direction; // true = up --- false = down
    float xCo;
    float yCo;
public:

    User();
    ~User();
    
    void setXY(float x, float y);

    void setX(float x);

    void setY(float y);

    float getX();

    float getY();

    bool getDirection();

    void setDirection(bool d);

    void drawUser();
};