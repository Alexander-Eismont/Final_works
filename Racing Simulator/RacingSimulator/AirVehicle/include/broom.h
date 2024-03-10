#pragma once

#include "airvehicle.h"

class Broom :public AirVehicle
{
public:
	Broom();

	double totalSpendTime(int distance) override;

	std::string getVehicleType() const override;

	bool isGroundVehicle() const override;
	bool isAirVehicle() const override;
};
