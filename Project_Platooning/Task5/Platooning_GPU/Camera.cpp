#include "Camera.h"

#include<vector>
#include<iostream>

using namespace std;


Camera::Camera() {
};



int Camera::findIndex(vector<Truck> vectTruck, Truck refT) {
    int j = 0;
    for (Truck i : vectTruck) {

        if (i.getTruckPlate() == refT.getTruckPlate()) {
            return j;
        }
        j++;
    }
}


bool Camera::captureIntruder(vector<Truck> vectTruck, Truck refT) {

    //int index = it - vectTruck.begin();

    int index = findIndex(vectTruck, refT);
    ///cout << index << endl;
    //cout << vectTruck.at(index).getPreviousTruckPlate() << "previous truck place by index" << endl;
    //cout << vectTruck.at(index - 1).getTruckPlate() << "previous truck place by index-1" << endl;


    if (index == 0) {
        return true;
    }
    else {
        if (vectTruck.at(index).getPreviousTruckPlate() == vectTruck.at(index - 1).getTruckPlate()) {


            return true;
        }
        else {

            cout << "intruder between truck " << index << " and " << index - 1 << endl;
            return false;

        }
    }
}

