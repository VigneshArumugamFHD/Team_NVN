#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <iostream>
#include <stdio.h>

using namespace std;

bool leadTruckselected; 
bool intruder_detected;
int front_truck_latitude;
int front_truck_longitude;
int measuredDistanceGap;


__global__ void AddIntsCUDA(int* a, int* b)
{
	a[0] += b[0];
}

int increment(int a)
{
	a+=1;
	return a;
}

void pcu_setup()
{
	leadTruckselected = false;
	intruder_detected = false;

	front_truck_latitude = 0;
	front_truck_longitude = 0;

	measuredDistanceGap = 0;

}


void updateCoordinates(double latitude, double longitude)
{
	cout << ("Front truck latitude before updating: ");
	cout << (front_truck_latitude);
	cout << ("Front truck longitude before updating: ");
	cout << (front_truck_longitude);
	front_truck_latitude = latitude;
	front_truck_longitude = longitude;
	cout << ("Front truck latitude after updating: ");
	cout << (front_truck_latitude);
	cout << ("Front truck longitude after updating: ");
	cout << (front_truck_longitude);
}

void updateIntruder(bool detected_status)
{
	if (detected_status == true)
	{
		intruder_detected = true;
	}
	else
	{
		intruder_detected = false;
	}
}


void updateGap(int16_t gap)
{
	measuredDistanceGap = gap;
}

int main() {

	bool leadTruckselected = false;
	bool intruder_detected = false;

	int front_truck_latitude = 0;
	int front_truck_longitude = 0;

	int measuredDistanceGap = 0;


	int a = 5, b = 9;
	int* d_a, * d_b; //device pointers

	cudaMalloc(&d_a, sizeof(int));
	cudaMalloc(&d_b, sizeof(int));

	cudaMemcpy(d_a, &a, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, &b, sizeof(int), cudaMemcpyHostToDevice);

	AddIntsCUDA << <3, 3 >> > (d_a, d_b);

	cudaMemcpy(&a, d_a, sizeof(int), cudaMemcpyDeviceToHost);

	cout << "The answer is " << a << endl;

	cudaFree(d_a);
	cudaFree(d_b);

	int c = 10;
	int updated_c = increment(c);
	

	cout << "Incremented c: "  << updated_c << endl;
	return 0;
}