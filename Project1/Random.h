#include <random>
// semi random int between 1and 100
int randomInt() {
    int randoPoint = rand() % 100 + 1;
    return randoPoint;
}
// semi random number in range bet
int randomFloor(int floors) {
    int randoPoint = rand() % floors + 1;

  
