#include "eagle.h"
#include "racingexception.h"
#include <iostream>

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
	double spendTime = 0;

	try
	{
		const double speed = this->getSpeed();
		
		if (speed == 0)
			throw RacingException("Cannot division by zero");

		const std::vector<double>& distanceReduction = getDistanceReduction();

		int valueInPercent = distanceReduction[0];

		double coefficient = (100 - static_cast<double>(valueInPercent)) / 100;

		spendTime = (static_cast<double>(distance) * coefficient) / speed;
	}
	catch (const RacingException& err)
	{
		std::cerr << err.what() << "\n";
		Eagle::totalSpendTime(distance);
	}

	return spendTime;
}

bool Eagle::isGroundVehicle() const { return false; }

bool Eagle::isAirVehicle() const { return true; }
