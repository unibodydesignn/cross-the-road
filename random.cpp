#include "random.h"

// Constructor of Random class
Random::Random() {

}

// Destructor of Random class
Random::~Random() {

}  

/*
 * @param float min - Minimum float number to generate
 * @param float max - Maximum float number to generate
 * @return Generated random float between min and max
 */
float Random::random_float(float min, float max) {
   float y = ((float)rand() / RAND_MAX) * (max - min) + min;
	return y;
}

/*
 * @param int min - Minimum integer number to generate
 * @param int max - Maximum integer number to generate
 * @return Generated random integer between min and max
 */
int Random::random_integer(int min, int max) {
   return min + (rand() % static_cast<int>(max - min + 1));
}