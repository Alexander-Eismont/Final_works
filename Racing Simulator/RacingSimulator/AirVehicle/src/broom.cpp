#include "broom.h"
#include "racingexception.h"
#include <iostream>

Broom::Broom()
	:AirVehicle()
{
	setVehicleType("Broom");
	setSpeed(20);
}

std::string Broom::getVehicleType() const
{
	return AirVehicle::getVehicleType();
}

/*
* Коэффициент сокращения расстояния увеличивается на 1% за каждую 1000
условную eдиницу расстояния
(Например, для расстояния 5600 коэффициент будет 5%)
* The distance reduction coefficient increases by 1% for every 1000
conventional unit of distance
(For example, for a distance of 5600 the coefficient will be 5%)
*/
double Broom::totalSpendTime(int distance)
{
	double spendTime = 0;

	try
	{
		const double speed = this->getSpeed();

		if (speed == 0)
			throw RacingException("Cannot division by zero");

		int valueInPercent = distance / 1000;

		double coefficient = (100 - static_cast<double>(valueInPercent)) / 100;

		double totalSpendTime = (static_cast<double>(distance) * coefficient) / speed;
	}
	catch (const RacingException& err)
	{
		std::cerr << err.what() << "\n";
		Broom::totalSpendTime(distance);
	}


	return spendTime;
}

bool Broom::isGroundVehicle() const { return false; }

bool Broom::isAirVehicle() const { return true; }
