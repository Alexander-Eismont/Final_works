#pragma once

#include <string>

class Vehicle
{
protected:
	Vehicle();

	void setVehicleType(std::string vehicleType);

	int getSpeed() const;
	void setSpeed(int speed);

public:
	virtual std::string getVehicleType() const;

	virtual bool isGroundVehicle() const;
	virtual bool isAirVehicle() const;

	virtual double totalSpendTime(int distance);

private:
	std::string m_vehicleType;
	int m_speed;
};
