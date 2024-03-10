#include "../include/allterrainboots.h"

AllTerrainBoots::AllTerrainBoots()
	: GroundVehicle()
{
	setVehicleType("All-terrain Boots");
	setSpeed(6);
	setDriveTime(60);
	setRestTime({ 10, 5 });
}

std::string AllTerrainBoots::getVehicleType() const
{
	return GroundVehicle::getVehicleType();
}

double AllTerrainBoots::totalSpendTime(int distance)
{
	return GroundVehicle::totalSpendTime(distance);
}

bool AllTerrainBoots::isGroundVehicle() const { return true; }

bool AllTerrainBoots::isAirVehicle() const { return false; }
