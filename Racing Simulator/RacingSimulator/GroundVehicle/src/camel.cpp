#include "camel.h"

Camel::Camel()
	: GroundVehicle()
{
	setVehicleType("Camel");
	setSpeed(10);
	setDriveTime(30);
	setRestTime({ 5, 8 });
}

std::string Camel::getVehicleType() const
{
	return GroundVehicle::getVehicleType();
}

double Camel::totalSpendTime(int distance)
{
	return GroundVehicle::totalSpendTime(distance);
}

bool Camel::isGroundVehicle() const { return true; }

bool Camel::isAirVehicle() const { return false; }
