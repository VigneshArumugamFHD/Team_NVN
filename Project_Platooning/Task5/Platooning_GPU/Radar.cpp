#include "Radar.h"
#include "Truck.h"
#include <math.h>


Radar::Radar() {
}

double Radar::captureGap(Truck t1, Truck t2) {


	double x_dis = t1.get_x_back_cor() - t2.get_x_front_cor();
	double y_dis = t1.get_y_back_cor() - t2.get_y_front_cor();


	return sqrt(x_dis * x_dis + y_dis * y_dis);
}