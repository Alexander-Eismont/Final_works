#pragma once

#include "groundvehicle.h"

class FastCamel : public GroundVehicle
{
public:
	FastCamel();

	double totalSpendTime(int distance) override;

	std::string getVehicleType() const override;

	bool isGroundVehicle() const override;
	bool isAirVehicle() const override;
};
