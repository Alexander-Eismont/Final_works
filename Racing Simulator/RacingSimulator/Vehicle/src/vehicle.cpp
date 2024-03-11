#include "vehicle.h"
#include "racingexception.h"

#include <iostream>

Vehicle::Vehicle()
	: m_vehicleType{ "Vehicle" }
	, m_speed(1)
{}

Vehicle::~Vehicle() {}

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
	try
	{
		if (m_speed != 0)
			return static_cast<double>(distance) / getSpeed();
		else
			throw RacingException("Cannot division by zero");
	}
	catch (const RacingException& err)
	{
		std::cerr << err.what() << "\n";
		return Vehicle::totalSpendTime(distance);
	}
}
