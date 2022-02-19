
#ifndef Truck_h
#define Truck_h

#include<string>
using namespace std;

class Truck
{
private:
	double x_front_cor;
	double y_front_cor;
	double x_back_cor;
	double y_back_cor;
	bool idle;
	bool on_move;
	string truckPlate;
	string previousTruckPlate;

public:

	Truck();
	
	string getTruckPlate();
	void setTruckPlate(string truck_plate);

	string getPreviousTruckPlate();
	void setPreviousTruckPlate(string previous_truck_plate);

	double get_x_front_cor();
	void set_x_front_cor(double xFrontCor);

	double get_y_front_cor();
	void set_y_front_cor(double yFrontCor);

	double get_x_back_cor();
	void set_x_back_cor(double xBackCor);

	double get_y_back_cor();
	void set_y_back_cor(double yBackCor);

	bool get_idle();
	void set_idle(bool Idle);

	bool get_on_move();
	void set_on_move(bool onMove);

	void updateCoordinates(double xFrontCor, double yFrontCor, double xBackCor, double yBackCor);


};

#endif