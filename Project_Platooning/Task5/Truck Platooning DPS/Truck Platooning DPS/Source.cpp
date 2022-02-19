#include<iostream>
#include "Truck.h"
#include "Radar.h"
#include "Camera.h"
#include <vector>

using namespace std;



void printVectorElemenst(vector<Truck> &vectTruck) {

	for (Truck i : vectTruck) {
		cout << i.getTruckPlate() << endl;
	}

}

int main() {
	Truck t1 =  Truck();
	Truck t2 = Truck();
	Truck t3 = Truck();
	Truck i1 = Truck();

	Radar r1 = Radar();
	Camera c1 = Camera();


	t1.set_x_front_cor(0.0);
	t1.set_y_front_cor(5.0);
	t1.set_x_back_cor(20.0);
	t1.set_y_back_cor(25.0);
	t1.setTruckPlate("10aa100");
	

	t2.set_x_front_cor(10.0);
	t2.set_y_front_cor(15.0);
	t2.set_x_back_cor(22.0);
	t2.set_y_back_cor(27.0);
	t2.setTruckPlate("10aa101");

	i1.set_x_front_cor(11.0);
	i1.set_y_front_cor(16.0);
	i1.set_x_back_cor(27.0);
	i1.set_y_back_cor(28.0);
	i1.setTruckPlate("10aa105");


	t3.set_x_front_cor(11.0);
	t3.set_y_front_cor(16.0);
	t3.set_x_back_cor(27.0);
	t3.set_y_back_cor(28.0);
	t3.setTruckPlate("10aa102");

	vector<Truck> vect;

	vect.push_back(t1);
	vect.push_back(t2);
	vect.push_back(t3);

	t2.setPreviousTruckPlate(vect.at(c1.findIndex(vect, t2)-1).getTruckPlate());
    t3.setPreviousTruckPlate(vect.at(c1.findIndex(vect, t3)-1).getTruckPlate());

	vect.at(c1.findIndex(vect, t2)) = t2;
	vect.at(c1.findIndex(vect, t3)) = t3;

	printVectorElemenst(vect);

	cout << endl << endl << endl;
	vect.insert(vect.begin() + 1, i1);

	printVectorElemenst(vect);

	cout << endl << endl << endl;



	cout << c1.captureIntruder(vect, t2) << " result from capture intruder function " << endl;


	return 0;

}

