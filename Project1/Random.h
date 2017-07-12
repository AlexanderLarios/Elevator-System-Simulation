#include <random>
class Random {
private:
    int randoint;
public:
    // semi random int between 1and 100
	Random() {
        randoint = rand() % 100 + 1;
	}
    // semi random number in range bet
    Random(int floors) {
        randoint = rand() % floors + 1;
    }
};
  
