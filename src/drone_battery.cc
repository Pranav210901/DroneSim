#include "drone_battery.h"

DroneBattery::DroneBattery(Drone* drone, double batteryLife) : BatteryDecorator(drone, batteryLife){
	this->drone = drone;
	this->batteryLife = batteryLife;
	needCharge = false; 
}
void DroneBattery::SetStationLoc(Vec3 loc) {
	stationLoc = loc;
}

void DroneBattery::Update(double dt) {
	//TODO:
	//Create a way for the drone to know when it must recharge based on Battery, Idea is to beeline to station when it's caculated
	Vec3 distance = stationLoc - drone->GetPosition();
	if (distance.GetX() < 3.0 && distance.GetZ() < 3.0) {
		if (batteryLife < 100.0) {
			batteryLife += dt;
		}
		else{
			needCharge = false;
		}
	}
	if (batteryLife <= 0) {
		drone->SetSpeed(0);
	}
	else {
		batteryLife -= dt;
		if (needCharge) {
			Beeline move;
			move.Move(drone->GetPosition(), stationLoc, drone->GetSpeed());
		}
	}
	if (batteryLife != 0) {
		drone->Update(dt);
	}
	else {
		drone->SetSpeed(0);
	}
}
void DroneBattery::FinishUpdate(double dt) {
	if (batteryLife < 5.0) {
		needCharge = true;
	}
}

