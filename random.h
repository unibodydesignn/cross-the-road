#include <random>

class Random {

public:
    Random();
    ~Random();

    float random_float(float min, float max);
    int random_integer(int min, int max);
};