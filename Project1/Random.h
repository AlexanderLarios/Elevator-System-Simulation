#include <cstdlib>
#include <ctime>

class Random {

public:

	Random() {
		std::srand(std::time(0));
	}

	Random(int seed) {
		std::srand(seed);
	}

	int next_int(int n) {
		return int(next_double() * n);
	}

	double next_double() {
		double num= double(std::rand()) / RAND_MAX;
		return num;
	}
  
  int defaultfloor(intnum_floors){
  
  int currentfloor;
  bool equal = true;
  return default floor;


int current_floor;
current_floor=int(std::random()%nfloor_num);
return current_floor;
	 
while (equal) {
default_floor=random()% nfloor_num;
if (current_floor !=default_floor) {
equal = false;
	
}	
}
return default floor;
};
