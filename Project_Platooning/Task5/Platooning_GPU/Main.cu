#include<iostream>
#include "Truck.h"
#include "Radar.h"
#include "Camera.h"
#include <vector>

#include <thread>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"


using namespace std;

Camera c1 = Camera();

vector<Truck> initializePlatoon() {

	int n;
	double first_turck_x_front_cor, first_turck_x_back_cor,
		first_turck_y_front_cor, first_turck_y_back_cor, dis,truck_Speed;
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
		cout << "Please insert speed of truck " << i << " :";
		cin >> truck_Speed;
		t.setSpeed(truck_Speed);
		t.setTruckPlate(plate_number);
		previous_truck_plate_number = plate_number;
		vect.push_back(t);

	}

	return vect;
}


vector<Truck> removeTruckFrom(vector<Truck> v, int id) {

	v.erase(v.begin() + id);
	return v;

}

void checkIntruder(vector<Truck> v, Truck refT) {
	cout << c1.captureIntruder(v, refT) << " id is : " << c1.findIndex(v, refT) << endl;
	//cout << c1.findIndex(v, refT) << endl;
}

void createThreads(vector<Truck> v) {

	int size = v.size();
	vector<thread> threads(size);
	int j = 0;
	for (Truck i : v) {
		threads[j] = thread(checkIntruder, v, i);
		j++;
	}


	for (auto& th : threads) {
		th.join();
	}
}

__global__ void arrangeSpeed(double* speed) {

	double avarageSpeed = 100.0;

	if (speed[0] < avarageSpeed)
	{
		while (speed[0] < avarageSpeed)
		{
			speed[0]+=1.0;
			printf("Current speed %f \n" , speed[0]);
		}
	}
	else {
		while(speed[0] > avarageSpeed)
		{
			speed[0]-=1.0;
			printf("Current speed %f \n", speed[0]);
		}

	}
	
	printf("Avarage speed achieved...\n");
}



int main() {
	Truck t1 = Truck();
	Truck t2 = Truck();
	Truck t3 = Truck();
	Truck i1 = Truck();

	Radar r1 = Radar();
	

	vector<Truck> platoon = initializePlatoon();


	createThreads(platoon);

	cout << endl << endl << endl;


	double speed_t1 = platoon.at(0).getSpeed();
	double* d_speed_t1; //device pointer

	double speed_t2 = platoon.at(1).getSpeed();
	double* d_speed_t2; //device pointer

	double speed_t3 = platoon.at(2).getSpeed();
	double* d_speed_t3; //device pointer


	cudaMalloc(&d_speed_t1, sizeof(double));
	cudaMalloc(&d_speed_t2, sizeof(double));
	cudaMalloc(&d_speed_t3, sizeof(double));




	cudaMemcpy(d_speed_t1, &speed_t1, sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy(d_speed_t2, &speed_t2, sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy(d_speed_t3, &speed_t3, sizeof(double), cudaMemcpyHostToDevice);




	cout << "Current speed of t1: " << platoon.at(0).getSpeed() << endl;
	cout << "Speed is setting to avarage speed for t1..." << endl;
	arrangeSpeed << < 1, 1 >> > (d_speed_t1);
	cout << "Current speed of t2: " << platoon.at(1).getSpeed() << endl;
	cout << "Speed is setting to avarage speed for t2..." << endl;
	arrangeSpeed << < 1, 1 >> > (d_speed_t2);
	cout << "Current speed of t3: " << platoon.at(2).getSpeed() << endl;
	cout << "Speed is setting to avarage speed for t3..." << endl;
	arrangeSpeed << < 1, 1 >> > (d_speed_t3);


	

	cudaMemcpy(&d_speed_t1, d_speed_t1, sizeof(double), cudaMemcpyDeviceToHost);
	cudaMemcpy(&d_speed_t2, d_speed_t2, sizeof(double), cudaMemcpyDeviceToHost);
	cudaMemcpy(&d_speed_t3, d_speed_t3, sizeof(double), cudaMemcpyDeviceToHost);
	



	cudaFree(d_speed_t1);
	cudaFree(d_speed_t2);
	cudaFree(d_speed_t3);


	return 0;

}

