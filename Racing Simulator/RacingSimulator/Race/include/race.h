#pragma once

#include "../../Vehicle/include/vehicle.h"

#include <string>
#include <vector>

class Race
{
public:
	void welcomeMessage();
	void raceMenu();
	std::string chooseRaceType(const int choice);
	void shuffleVehicles(std::vector<Vehicle*>& allVehicles);
	void registrationMessage(const std::string& raceType, const int distance);
	void registrationVehiclesOptions(const std::vector<Vehicle*>& vehicles);
	void vehicleRegistration(std::vector<Vehicle*>& registeredVehicles,
							 const std::vector<Vehicle*>& allVehicles,
							 const std::string& raceType,
							 const int distance,
							 const int choice);
	void printResult(std::vector<Vehicle*> registeredVehicles,
					 const int distance);

	void handleInvalidInput();
	void handleInputWinthin();
	void handleInputDistance();
	void clearTerminal();

private:
	enum RaceType
	{
		GROUND_VEHICLE = 1,
		AIR_VEHICLE = 2,
		MIXED_VEHICLE = 3
	};

	void clearAndIgnoreCin();
	void printVehiclesList(const std::vector<Vehicle*>& vehicles);
	bool isTypesSame(const std::string& raceType, Vehicle* vehicle);
	void printMessage(const std::string& message);
	void printRegisteredVehicles(const std::vector<Vehicle*>& vehicles);
};
