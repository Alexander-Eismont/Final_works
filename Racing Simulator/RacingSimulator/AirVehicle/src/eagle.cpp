#include "../include/eagle.h"

Eagle::Eagle()
	:AirVehicle()
{
	setVehicleType("Eagle");
	setSpeed(8);
	setDistanceReduction({ 6 }); // в процентах/in persentage
}

std::string Eagle::getVehicleType() const
{
	return AirVehicle::getVehicleType();
}

/*
* Коэффициент сокращения расстояния всегда 6%
* The distance reduction factor is always 6%
*/
double Eagle::totalSpendTime(int distance)
{
	const double speed = this->getSpeed();
	const std::vector<double>& distanceReduction = getDistanceReduction();

	int valueInPercent = distanceReduction[0];

	double coefficient = (100 - static_cast<double>(valueInPercent)) / 100;

	double totalSpendTime = (static_cast<double>(distance) * coefficient) / speed;

	return totalSpendTime;
}

bool Eagle::isGroundVehicle() const { return false; }

bool Eagle::isAirVehicle() const { return true; }
