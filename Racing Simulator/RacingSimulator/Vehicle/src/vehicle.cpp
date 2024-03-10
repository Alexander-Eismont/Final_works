#include "../include/vehicle.h"

Vehicle::Vehicle()
{
	setVehicleType("Vehicle");
	setSpeed(1);
}

std::string Vehicle::getVehicleType() const { return m_vehicleType; }

void Vehicle::setVehicleType(std::string vehicleType)
{
	m_vehicleType = vehicleType;
}

int Vehicle::getSpeed() const { return m_speed; }

void Vehicle::setSpeed(int speed) { m_speed = speed; }

bool Vehicle::isGroundVehicle() const { return false; }

bool Vehicle::isAirVehicle() const { return false; }

double Vehicle::totalSpendTime(int distance)
{
	return static_cast<double>(distance) / getSpeed();
}
