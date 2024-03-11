#pragma once

#include "groundvehicle.h"

class AllTerrainBoots : public GroundVehicle
{
public:
	AllTerrainBoots();

	double totalSpendTime(int distance) override;

	std::string getVehicleType() const override;

	bool isGroundVehicle() const override;
	bool isAirVehicle() const override;
};
