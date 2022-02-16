#include "PCU.cuh"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

int CurrentVelocity;
double CurrentSteeringAngle;
bool leadTruckselected;
bool intruder_detected;
char sendingData[10] = { 'v','e','l','a','n','g','p','o','s','\0' };
char receivedData[10];
double front_truck_latitude;
double front_truck_longitude;
int measuredDistanceGap;

#define DESIRED_DISTANCE_GAP 100  /*10 meters*/


pcu::pcu()
{

}

__global__ void pcu::pcu_setup()
{
	leadTruckselected = false;
	intruder_detected = false;

	front_truck_latitude = 0;
	front_truck_longitude = 0;

	measuredDistanceGap = 0;

	leadTruckselected = false;//getLeadTruckSelected();
}


__global__ void pcu::pcu_loop()
{
	CurrentVelocity = 100;
	CurrentSteeringAngle = 100;

	if (leadTruckselected == true)
	{
		serializeData();
	}
	else
	{
		deserializeData();
		dataProcesssing();
		serializeData();
	}

}


__global__ void pcu::serializeData()
{

}

__global__ void pcu::deserializeData()
{


}

__global__ void pcu::dataProcesssing()
{
	if (measuredDistanceGap < DESIRED_DISTANCE_GAP)
	{
		printf("Decreasing Speed : Measured_Distance = ");
		printf("%d", measuredDistanceGap);
	}
	else
	{
		printf("Increasing Speed : Measured_Distance = ");
		printf("%d", measuredDistanceGap);
	}



	if (intruder_detected == true)
	{
		printf("Intruder detected Decreasing Speed");
	}
	else
	{
		printf("Maintaining Speed");
	}
}

__global__ void pcu::updateCoordinates(double latitude, double longitude)
{
	printf("Front truck latitude before updating: ");
	printf("%f", front_truck_latitude);
	printf("Front truck longitude before updating: ");
	printf("%f", front_truck_longitude);
	front_truck_latitude = latitude;
	front_truck_longitude = longitude;
	printf("Front truck latitude after updating: ");
	printf("%f", front_truck_latitude);
	printf("Front truck longitude after updating: ");
	printf("%f", front_truck_longitude);
}

__global__ void pcu::updateGap(int gap)
{
	measuredDistanceGap = gap;
}

__global__ void pcu::updateIntruder(bool detected_status)
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

__global__ void pcu::updateRxFrame(char* frame)
{
	char* temp = receivedData;
	temp = frame;
	printf("Received data from the front truck");
}