#pragma once

#include "vehicle.h"
#include <vector>

class GroundVehicle : public Vehicle
{
protected:
	GroundVehicle();

	int getDriveTime() const;
	void setDriveTime(int driveTime);

	std::vector<double> getRestTime() const;
	void setRestTime(std::vector<double> restTime);

	double totalSpendTime(int distance) override;

public:
	virtual ~GroundVehicle();

	std::string getVehicleType() const override = 0;

	bool isGroundVehicle() const override;
	bool isAirVehicle() const override;

private:
	int m_driveTime;
	std::vector<double> m_restTime;
};
