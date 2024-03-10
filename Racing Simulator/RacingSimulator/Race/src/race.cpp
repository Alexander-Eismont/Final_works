#include "race.h"
#include "../include/race.h"
#include "../../RacingException/include/racingexception.h"

#include <algorithm>
#include <iostream>
#include <random>

void Race::welcomeMessage()
{
	std::cout << "Welcome to the racing simulator!\n";
}

void Race::raceMenu()
{
	std::cout << "Select race type or 0 for exit:\n";
	std::cout << "1. Ground transport race.\n";
	std::cout << "2. Air transport race.\n";
	std::cout << "3. Race of land and air transport.\n";
	std::cout << "0. Exit.\n";
}

std::string Race::chooseRaceType(const int choice)
{
	switch (choice)
	{
	case(Race::RaceType::GROUND_VEHICLE):
		return "Ground";
	case(Race::RaceType::AIR_VEHICLE):
		return "Air";
	case(Race::RaceType::MIXED_VEHICLE):
		return "Mixed";
	default:
		return "";
	}
}

// обработка некорректного ввода (если введено не число, а символы)
// processing incorrect input (if symbols, not numbers, are entered)
void Race::handleInvalidInput()
{
	clearAndIgnoreCin();
	throw RacingException("Invalid input. Please enter a number!");
}

// обработка ввода, если введено число не в заданных пределах
// input processing if the number entered is not within the specified limits
void Race::handleInputWinthin()
{
	std::cin.clear();
	clearAndIgnoreCin();
	throw RacingException("Invalid entries. "
						  "Enter a number within the given limits!");
}

// обработка неверного ввода дистанции (0 или меньше 0)
// processing incorrect distance input (0 or less than 0)
void Race::handleInputDistance()
{
	clearAndIgnoreCin();
	throw RacingException("Invalid input. Distance cannot be 0 or less than 0!");
}

// очистка ввода cin
// clear cin
void Race::clearAndIgnoreCin()
{
	//сброс флагов ошибок ввода/вывода, иначе остальные попытки будут недействительны
	//clear I/O error flags, otherwise other input attempts will be invalid
	std::cin.clear();

	// игнорирование всех символов на входе до символа '\n'
	// ignores all input characters up to '\n'
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// перемешивание ТС, чтобы они были не по порядку
// mixing the vehicles so that they are not in order
void Race::shuffleVehicles(std::vector<Vehicle*>& allVehicles)
{
	/*
	* std::shuffle - перемешивание элементов в контейнере
	allVehicles.begin(), allVehicles.end() - это итераторы, указывающие на
	начало и конец контейнера allVehicles
	std::mt19937(std::random_device()()) - это объект генератора случайных
	чисел типа std::mt19937. std::random_device() используется для создания
	случайного начального состояния генератора. Конструктор std::mt19937
	принимает начальное состояние в качестве аргумента.
	Таким образом, std::mt19937(std::random_device()()) создает объект
	генератора случайных чисел с случайным начальным состоянием.
	() в конце - это вызов конструктора std::mt19937. Он вызывается сразу после
	std::random_device(), чтобы создать объект генератора случайных чисел.

	* std::shuffle - mixing the elements in the container
	allvehicles.begin(), allvehicles.end () - these are iterators indicating
	the beginning and end of the container Allvehicles
	std::mt19937(std::random_device()()) - this is an object of random
	generator Numbers like std::mt19937. std::random_device() is used to create
	an accidental initial state of the generator. Designer std::mt19937 accepts
	the initial state as an argument.
	Thus, std::mt19937 (std::random_device()()) creates an object of random
	numbers generator with an accidental initial state.
	() At the end - this is a call to the std designer::mt19937. It is called
	immediately after the std::random_device() to create an object of the
	random number generator.
	*/
	std::shuffle(allVehicles.begin(), allVehicles.end(),
		std::mt19937(std::random_device()()));
}

// вывод сообщения о регистрации ТС и расстоянии
// displaying a message about vehicle registration and distance
void Race::registrationMessage(const std::string& raceType, const int distance)
{
	std::cout << "Registrate the vehicle on the " << raceType <<
		" race! Distance: " << distance << "\n";
}

// вывод списка ТС и сообщения о выборе пунктов списка
// displaying a list of vehicles and messages about selecting list items
void Race::registrationVehiclesOptions(const std::vector<Vehicle*>& vehicles)
{
	printVehiclesList(vehicles);
	std::cout << "0. Finish registration" << "\n";
	std::cout << "Select vehicle or 0 to exit registration menu.\n";
}

// печать всех видов ТС в виде списка
// printing of all types of vehicles in the form of a list
void Race::printVehiclesList(const std::vector<Vehicle*>& vehicles)
{
	int index = 1;
	for (const auto& vehicle : vehicles)
		std::cout << index++ << ". " << vehicle->getVehicleType() << "\n";
}

// очистка терминала (консоли)
// clear terminal (console)
void Race::clearTerminal()
{
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}

// регистрация ТС на гонку
// vehicle registration for the race
void Race::vehicleRegistration(std::vector<Vehicle*>& registeredVehicles,
							   const std::vector<Vehicle*>& allVehicles,
							   const std::string& raceType,
							   const int distance,
							   const int choice)
{
	// выбранное пользователем ТС -1, т.к. индексы в векторе начинаются с 0
	// user-selected vehicle "-1", because indexes in the vector start at 0
	Vehicle* selectedVehicle = allVehicles[choice - 1];

	// вывод сообщения об удачной или неудачной регистрации ТС на гонку
	// displaying a message about successful or unsuccessful vehicle 
	// registration for the race
	std::string message;

	// проверка на совпадение типа ТС и типа гонки
	// checking for a match between vehicle type and race type
	if (isTypesSame(raceType, selectedVehicle))
	{
		// проверка было ли уже ТС зарегистрировано на гонку
		// проверка было ли уже ТС зарегестрировано на гонку
		if (std::find(registeredVehicles.begin(), registeredVehicles.end(),
			selectedVehicle) == registeredVehicles.end())
		{
			// добавление ТС в список зарегистрированных на гонку
			//	adding a vehicle to the list of registered for the race	
			registeredVehicles.push_back(selectedVehicle);

			// сообщение об успешной регистрации ТС
			// message about successful vehicle registration
			message = selectedVehicle->getVehicleType() + " successfuly added\n";
		}
		else
			message = "Vehicle already registered!\n";
	}
	else
		message = "You have tried to register the wrong type of vehicle for "
		"this type of race\n";

	// вывод сообщения на экран
	// displaying a message on the screen
	printMessage(message);

	// повторный запуск функций для регистрации ТС
	// relaunch of functions for vehicle registration
	registrationMessage(raceType, distance);
	registrationVehiclesOptions(allVehicles);

	// вывод списка зарегистрированных ТС 
	// displaying a list of registered vehicles
	std::cout << "Registered vehicles: ";
	printRegisteredVehicles(registeredVehicles);
}

// проверка на совпадение типа ТС и выбранного типа гонки
// checking for a match between the vehicle type and the selected race type
bool Race::isTypesSame(const std::string& raceType, Vehicle* vehicle)
{
	return ((raceType == "Ground" && vehicle->isGroundVehicle()) ||
			(raceType == "Air" && vehicle->isAirVehicle()) ||
			(raceType == "Mixed"));
}

// вывод списка уже зарегистрированных ТС
// displaying a list of already registered vehicles
void Race::printRegisteredVehicles(const std::vector<Vehicle*>& vehicles)
{
	for (int i = 0; i < vehicles.size(); i++)
	{
		std::cout << vehicles[i]->getVehicleType();
		(i < vehicles.size() - 1) ? std::cout << ", " : std::cout << "\n";
	}
}

// печать сообщений об успешной или неуспешной регистрации ТС
// printing messages about successful or unsuccessful vehicle registration
void Race::printMessage(const std::string& message)
{
	clearTerminal();
	std::cout << message;
}

// вывод результатов гонки
// output of race results
void Race::printResult(std::vector<Vehicle*> registeredVehicles,
					   const int distance)
{
	// сортировка ТС. На вход подается начало вектора, его последний элемент
	// и пользовательская функция сравнения, которая используется для сравнения.
	// В данном случае используется лямбда-выражение. На ее вход передаются 
	// указателя на объекты Vehicle* и сравнивает их между собой по времени.
	// [distance] - переменная, которая передаетя в методы
	// vehicle sorting. The input is the beginning of the vector, its last 
	// element, and a custom comparison function that is used for comparison. 
	// In this case, a lambda expression is used. A pointer to Vehicle* objects 
	// is passed to its input and compares them with each other in time. 
	// [distance] - a variable that is passed to methods
	std::sort(registeredVehicles.begin(), registeredVehicles.end(),
		[distance](Vehicle* a, Vehicle* b)
		{
			return a->totalSpendTime(distance) < b->totalSpendTime(distance);
		});

	std::cout << "Result:\n";

	for (const auto& vehicle : registeredVehicles)
		std::cout << vehicle->getVehicleType() << ". Time: " <<
		vehicle->totalSpendTime(distance) << "\n";
}
