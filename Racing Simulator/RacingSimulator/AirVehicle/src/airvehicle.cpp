#include "airvehicle.h"
#include "racingexception.h"
#include <iostream>

AirVehicle::AirVehicle()
	: Vehicle()
{
	setVehicleType("Air");
	setDistanceReduction({ 0 });
}

AirVehicle::~AirVehicle() {}

std::string AirVehicle::getVehicleType() const
{
	return Vehicle::getVehicleType();
}

void AirVehicle::setDistanceReduction(std::vector<double> distanceReduction)
{
	m_distanceReduction = distanceReduction;
}

std::vector<double> AirVehicle::getDistanceReduction() const
{
	return m_distanceReduction;
}

double AirVehicle::totalSpendTime(int distance)
{
	double spendTime = 0;

	try
	{
		double speed = this->getSpeed();
	
		if (speed == 0)
			throw RacingException("Cannot division by zero");

		const std::vector<double>& distanceReduction = getDistanceReduction();

		int valueInPercent = distanceReduction[0];

		/*
		* перевод сокращения дистанции из процентов в коэффициент.
		(если дистанция сокращается на 5 процентов, то коэффициент будет 0.95)
		* converting distance reduction from percentage to coefficient
		(if the distance is reduced by 5 percent, the coefficient will be 0.95)
		*/
		double coefficient = (100 - valueInPercent) / 100;

		spendTime = (static_cast<double>(distance) * coefficient) / speed;
	}
	catch (const RacingException& err)
	{
		std::cerr << err.what() << "\n";
		AirVehicle::totalSpendTime(distance);
	}

	return spendTime;
}

bool AirVehicle::isGroundVehicle() const { return false; }

bool AirVehicle::isAirVehicle() const { return true; }
