
#include "Truck.h"
#include "Radar.h"
#include "Camera.h"
#include <vector>
#include <thread>
#include <iostream>

using namespace std;



Camera c1 = Camera();


vector<Truck> removeTruckFrom(vector<Truck> v, int id) {
	
	v.erase(v.begin() + id);
	return v;

}

vector<Truck> initializePlatoon() {

	int n;
	double first_turck_x_front_cor, first_turck_x_back_cor,
		first_turck_y_front_cor, first_turck_y_back_cor, dis;
	string plate_number;
	string previous_truck_plate_number = "";          




	cout << "Please insert number of trucks in the platoon:";
	cin >> n;
	cout << "Please insert front x coordinate of truck 1:";
	cin >> first_turck_x_front_cor;
	cout << "Please insert back x coordinates of truck 1:";
	cin >> first_turck_x_back_cor;
	cout << "Please insert front y coordinate of truck 1 :";
	cin >> first_turck_y_front_cor;
	cout << "Please insert front y coordinate of truck 1 :";
	cin >> first_turck_y_back_cor;
	//cout << "Please insert plate number of truck 1 :";
	//cin >> plate_number;
	cout << "Please enter desired distance between the trucks:";
	cin >> dis;

	//cout << plate_number;
	//getline(cin, fullName);

	vector<Truck > vect;

	for (int i = 1; i <= n; i++) {
		Truck t = Truck();

		
		t.set_x_front_cor(first_turck_x_back_cor + (i - 1) * dis);
		t.set_x_back_cor(first_turck_x_back_cor + (i - 1) * dis);
		t.set_y_front_cor(first_turck_y_front_cor);
		t.set_y_back_cor(first_turck_y_back_cor);
		t.setPreviousTruckPlate(previous_truck_plate_number);

		cout << "Please insert plate number of truck " << i << " :";
		cin >> plate_number;
		t.setTruckPlate(plate_number);
		previous_truck_plate_number = plate_number;
		vect.push_back(t);

	}

	return vect;
}


void printVectorElemenst(vector<Truck> &vectTruck) {

	for (Truck i : vectTruck) {
		//cout << i.get_x_front_cor();
		//cout << endl;
		//cout << i.get_x_back_cor() ;
		//cout << endl;
		//cout << i.get_y_front_cor() ;
		//cout <<  endl;
		//cout << i.get_y_back_cor();
		//cout << endl;
		cout << i.getTruckPlate() << "  ==> ";
		cout << i.getPreviousTruckPlate() ;
		//cout << endl;
		
		cout << endl;
	}

}

void doSomething(vector<Truck> v,  Truck refT) {
	cout << c1.captureIntruder(v, refT) << " id is : " << c1.findIndex(v, refT) << endl;
	//cout << c1.findIndex(v, refT) << endl;g
}

void checkIntruder(vector<Truck> v) {

	int size = v.size();
	vector<thread> threads(size);
	int j = 0;
	for (Truck i : v) {
		threads[j] = thread(doSomething,v, i);
		j++;
	}


	for (auto& th : threads) {
		th.join();
	}
}

int main() {
	Truck t1 =  Truck();
	Truck t2 = Truck();
	Truck t3 = Truck();
	Truck i1 = Truck();

	Radar r1 = Radar();
	Camera c1 = Camera();

	vector<Truck> platoon = initializePlatoon();

	//printVectorElemenst(platoon);
	//platoon = removeTruckFrom(platoon, 1);
	
	checkIntruder(platoon);
	//printVectorElemenst(platoon);

	
	

	//printVectorElemenst(vect);

	//cout << n << endl;

	/*
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

	*/
	return 0;

}

