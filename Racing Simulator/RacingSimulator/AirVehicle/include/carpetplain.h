#pragma once

#include "airvehicle.h"

class CarpetPlain :public AirVehicle
{
public:
	CarpetPlain();

	double totalSpendTime(int distance) override;

	std::string getVehicleType() const override;

	bool isGroundVehicle() const override;
	bool isAirVehicle() const override;
};
