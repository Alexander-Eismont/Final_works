#include "centaur.h"

Centaur::Centaur()
	: GroundVehicle()
{
	setVehicleType("Centaur");
	setSpeed(15);
	setDriveTime(8);
	setRestTime({ 2 });
}

std::string Centaur::getVehicleType() const
{
	return GroundVehicle::getVehicleType();
}

double Centaur::totalSpendTime(int distance)
{
	return GroundVehicle::totalSpendTime(distance);
}

bool Centaur::isGroundVehicle() const { return true; }

bool Centaur::isAirVehicle() const { return false; }
