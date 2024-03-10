#include "../include/fastcamel.h"

FastCamel::FastCamel()
	: GroundVehicle()
{
	setVehicleType("Fast Camel");
	setSpeed(40);
	setDriveTime(10);
	setRestTime({ 5, 6.5, 8 });
}

std::string FastCamel::getVehicleType() const
{
	return GroundVehicle::getVehicleType();
}

double FastCamel::totalSpendTime(int distance)
{
	return GroundVehicle::totalSpendTime(distance);
}

bool FastCamel::isGroundVehicle() const { return true; }

bool FastCamel::isAirVehicle() const { return false; }
