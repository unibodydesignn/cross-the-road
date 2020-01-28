#include "random.h"

Random::Random() {

}

Random::~Random() {

}

float Random::random_float(float min, float max) {
   float y = ((float)rand() / RAND_MAX) * (max - min) + min;
	return y;
}

int Random::random_integer(int min, int max) {
   return min + (rand() % static_cast<int>(max - min + 1));
}