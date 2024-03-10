#include "../include/carpetplain.h"

CarpetPlain::CarpetPlain()
	:AirVehicle()
{
	setVehicleType("Carpet Plain");
	setSpeed(10);
	setDistanceReduction({ 0, 3, 10, 5 }); // в процентах/in persentage
}

std::string CarpetPlain::getVehicleType() const
{
	return AirVehicle::getVehicleType();
}

/*
* Коэффициент сокращения расстояния:
- если расстояние меньше 1000 — без сокращения
- если расстояние меньше 5000 — 3%
- если расстояние меньше 10000 — 10%
- если расстояние больше или равно 10000 — 5%
* Distance reduction factor:
- if the distance is less than 1000 - without reduction
- if the distance is less than 5000 - 3%
- if the distance is less than 10000 - 10%
- if the distance is greater than or equal to 10000 - 5%
*/
double CarpetPlain::totalSpendTime(int distance)
{
	const double speed = this->getSpeed();
	const std::vector<double>& distanceReduction = getDistanceReduction();

	double valueInPercent;

	if (distance < 1000)
		valueInPercent = distanceReduction[0];
	else if (distance < 5000)
		valueInPercent = distanceReduction[1];
	else if (distance < 10000)
		valueInPercent = distanceReduction[2];
	else
		valueInPercent = distanceReduction[3];

	double coefficient = (100 - valueInPercent) / 100;

	double totalSpendTime = (static_cast<double>(distance) * coefficient) / speed;

	return totalSpendTime;
}

bool CarpetPlain::isGroundVehicle() const { return false; }

bool CarpetPlain::isAirVehicle() const { return true; }
