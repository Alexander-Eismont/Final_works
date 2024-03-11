#pragma once

#include "groundvehicle.h"

class Centaur : public GroundVehicle
{
public:
	Centaur();

	double totalSpendTime(int distance) override;

	std::string getVehicleType() const override;

	bool isGroundVehicle() const override;
	bool isAirVehicle() const override;
};
