#ifndef Camera_h
#define Camera_h

#include <vector>
#include "Truck.h"
using namespace std;

class Camera
{
public:
	Camera();
	int findIndex(vector<Truck> vectTruck, Truck refT);
	bool captureIntruder(vector<Truck> vectTruck, Truck refT);
	
};


#endif // !Camera_h