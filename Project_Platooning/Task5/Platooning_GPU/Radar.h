

#ifndef Radar_h
#define Radar_h
// DEBUG
#include "Truck.h"


class Radar
{

public:
	Radar();
	double captureGap(Truck t1, Truck t2);
};

#endif