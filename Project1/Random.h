#include <random>
// semi random int between 1and 100
int Random() {
    int randoPoint = rand() % 100 + 1;
    return randoPoint;
}
// semi random number in range bet
int Random(int floors) {
    int randoPoint = rand() % floors + 1;

  
