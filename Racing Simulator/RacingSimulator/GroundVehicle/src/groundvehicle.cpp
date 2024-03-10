#include "../include/groundvehicle.h"

GroundVehicle::GroundVehicle()
	: Vehicle()
{
	setVehicleType("Ground");
	setDriveTime(0);
	setRestTime({ 0 });
}

std::string GroundVehicle::getVehicleType() const
{
	return Vehicle::getVehicleType();
}

void GroundVehicle::setDriveTime(int driveTime) { m_driveTime = driveTime; }

int GroundVehicle::getDriveTime() const { return m_driveTime; }

void GroundVehicle::setRestTime(std::vector<double> restTime)
{
	m_restTime = restTime;
}

std::vector<double> GroundVehicle::getRestTime() const
{
	return m_restTime;
}

double GroundVehicle::totalSpendTime(int distance)
{
	const double speed = this->getSpeed();
	const std::vector<double>& restTime = getRestTime();
	const double driveTime = getDriveTime();

	double distanceTraveled = 0;
	double totalSpendTime = 0;

	// расчет количества часов потраченных на гонку без учета отдыха
	// total number of hours required for the race without rest
	double timeWithoutRest = static_cast<double>(distance) / speed;

	distanceTraveled += speed * driveTime;

	// проверка может ли ТС преодолеть дистанцию без отдыха
	// checking whether the vehicle can cover the distance without resting
	if (distanceTraveled >= distance)
		return timeWithoutRest;

	// индекс для получения времени отдыха из вектора
	// index for getting rest time from vector
	int index = 0;

	// увеличение общего затраченного времени на время первого заезда и отдыха
	// increase in total time by the time spent on the first trip and rest
	totalSpendTime += driveTime;
	totalSpendTime += restTime[index];

	// рассчитываем общее затраченное время пока дистаници не пройдена
	// calculate the total time spent until the distance is completed
	while (distanceTraveled < distance)
	{
		index++;

		if (index > restTime.size() - 1)
			index = restTime.size() - 1;

		double currentRest = restTime[index];
		double remainingDistance = static_cast<double>(distance) - distanceTraveled;

		/*
		* если за заезд не удается закончить оставшуюся дистанцию, то проводим
		расчет времени и пройденного расстояния, иначе общее время увеличиваем
		на время до конца заезда и выходим
		* if it is not possible to complete the remaining distance during the
		race, then we calculate the time and distance traveled, otherwise we
		increase the total time by the time until the end of the race and exit
		*/
		if (driveTime * speed < remainingDistance)
		{
			totalSpendTime += driveTime;
			totalSpendTime += currentRest;
			distanceTraveled += speed * driveTime;
		}
		else
		{
			totalSpendTime += remainingDistance / speed;
			distanceTraveled = static_cast<double>(distance);
		}
	}

	return totalSpendTime;
}

bool GroundVehicle::isGroundVehicle() const { return true; }

bool GroundVehicle::isAirVehicle() const { return false; }
