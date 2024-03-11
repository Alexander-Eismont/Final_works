#pragma once

#include "airvehicle.h"

class Eagle :public AirVehicle
{
public:
	Eagle();

	double totalSpendTime(int distance) override;

	std::string getVehicleType() const override;

	bool isGroundVehicle() const override;
	bool isAirVehicle() const override;
};
