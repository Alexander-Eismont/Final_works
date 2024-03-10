#pragma once

#include "../../Vehicle/include/vehicle.h"
#include <vector>

class AirVehicle : public Vehicle
{
protected:
	AirVehicle();

	std::vector<double> getDistanceReduction() const;
	void setDistanceReduction(std::vector<double> distanceReduction);

	double totalSpendTime(int distance) override;

public:
	std::string getVehicleType() const override;

	bool isGroundVehicle() const override;
	bool isAirVehicle() const override;
	
private:
	std::vector<double> m_distanceReduction; // в процентах/in percentages
};
