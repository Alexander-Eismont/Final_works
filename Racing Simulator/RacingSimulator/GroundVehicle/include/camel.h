#pragma once

#include "groundvehicle.h"

class Camel : public GroundVehicle
{
public:
	Camel();

	double totalSpendTime(int distance) override;

	std::string getVehicleType() const override;

	bool isGroundVehicle() const override;
	bool isAirVehicle() const override;
};
