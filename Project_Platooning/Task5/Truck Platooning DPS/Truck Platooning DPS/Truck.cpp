#include "Truck.h"



Truck::Truck() {
	idle = false;
	on_move = false;
	previousTruckPlate = "";
};





	
	double Truck::get_x_front_cor() {
		return x_front_cor;
	}
	void Truck::set_x_front_cor(double xFrontCor) {
		x_front_cor = xFrontCor;
	}

	double Truck::get_y_front_cor() {
		return y_front_cor;
	}
	void Truck::set_y_front_cor(double yFrontCor) {
		y_front_cor = yFrontCor;
	}
 /*double Truck::get_x_front_cor() {
		return x_front_cor;
	}
	void Truck::set_x_front_cor(double xFrontCor) {
		x_front_cor = xFrontCor;
	}
	
	double Truck::get_y_front_cor() {
		return y_front_cor;
	}
	void Truck::set_y_front_cor(double yFrontCor) {
		y_front_cor = yFrontCor;
	}
	*/


	double Truck::get_x_back_cor() {
		return x_back_cor;
	}
	void Truck::set_x_back_cor(double xBackCor) {
		x_back_cor = xBackCor;
	}

	double Truck::get_y_back_cor() {
		return y_front_cor;
	}
	void Truck::set_y_back_cor(double yBackCor) {
		y_front_cor = yBackCor;
	}




	bool Truck::get_idle() {
		return idle;
	}
	void Truck::set_idle(bool Idle) {
		idle = Idle;
	}

	bool Truck::get_on_move() {
		return on_move;
	}
	void Truck::set_on_move(bool onMove) {
		on_move = onMove;
	}

	void Truck::updateCoordinates(double xFrontCor, double yFrontCor, double xBackCor,double yBackCor) {
		x_front_cor = xFrontCor;
		y_front_cor = yFrontCor;

		x_back_cor = xBackCor;
		y_back_cor = yBackCor;

	}

	string Truck::getTruckPlate() {
		return truckPlate;
	}
	void Truck::setTruckPlate(string truck_plate) {
		truckPlate = truck_plate;
	}

	string Truck::getPreviousTruckPlate() {
		return previousTruckPlate;
	}
	void Truck::setPreviousTruckPlate(string previous_truck_plate) {
		previousTruckPlate = previous_truck_plate;
	}

	void Truck::setTruckId(int ID) {
		truck_id = ID;
	}


	int Truck::getId() {
		return truck_id;
	}