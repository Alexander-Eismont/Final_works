#include "RacingException/include/racingexception.h"
#include "Race/include/race.h"

#include "../../GroundVehicle/include/allterrainboots.h"
#include "../../GroundVehicle/include/camel.h"
#include "../../GroundVehicle/include/centaur.h"
#include "../../GroundVehicle/include/fastcamel.h"
#include "../../AirVehicle/include/broom.h"
#include "../../AirVehicle/include/carpetplain.h"
#include "../../AirVehicle/include/eagle.h"

#include <iostream>

const int START_MENU_OPTIONS = 3;
const int LAST_MENU_OPTIONS = 2;
const int EXIT = 0;

void startRace(Race& race, std::vector<Vehicle*>& allVehicles);
int getUserChoice(Race& race, int limit);
int getDistance(Race& race);

void registrationVehicleMenu(std::vector<Vehicle*>& registeredVehicles,
						const std::vector<Vehicle*>& allVehicles,
						const std::string& raceType,
						const int distance,
						Race& race);


void startOrRegistrationMenu(std::vector<Vehicle*>& registeredVehicles,
		 const std::vector<Vehicle*>& allVehicles,
		 Race& race,
		 const std::string& raceType,
		 const int distance);

void againOrExitMenu(Race& race, std::vector<Vehicle*>& allVehicles);

int main()
{
	// создание объектов каждого вида ТС
	// creation of objects of each type of vehicle
	Camel camel;
	FastCamel fastCamel;
	Centaur centaur;
	AllTerrainBoots allTerrainBoots;
	CarpetPlain carpetPlain;
	Eagle eagle;
	Broom broom;

	/*
	* создается вектор указателей, т.к. если создать обычный вектор с
	родительским классом без указателя, то будет срез объектов под
	родительский класс и методы дочерних не будут учитываться. А объекты
	добавляются по ссылке
	* A vector of pointers is created, because If you create an ordinary
	vector with the parental class without a pointer, there will be a cut of
	objects for the parent class and the methods of subsidiaries will not be
	taken into account. And objects are added by the link
	*/
	std::vector<Vehicle*> allVehicles;

	// добавление каждого ТС в список всех
	// adding each vehicle to the list of all
	allVehicles.push_back(&camel);
	allVehicles.push_back(&fastCamel);
	allVehicles.push_back(&centaur);
	allVehicles.push_back(&allTerrainBoots);
	allVehicles.push_back(&carpetPlain);
	allVehicles.push_back(&eagle);
	allVehicles.push_back(&broom);

	// создание объекта гонки
	// creating a race object
	Race race;

	// основной запуск игры (все меню, регистрации и сама гонка)
	// main launch of the game (all menus, registrations and the race itself)
	startRace(race, allVehicles);

	system("pause");

	return 0;
}

void startRace(Race& race, std::vector<Vehicle*>& allVehicles)
{
	// приветствие
	// greetings
	race.welcomeMessage();

	// вывод видов гонок
	// output of race types
	race.raceMenu();

	/*
	* получение числа от пользователя, обозначающее тип гонки
	если код равен 0, то выход из игры
	* receiving a number from the user indicating the type of race; 
	if the code is 0, then exit the game
	*/
	int raceTypeCode = getUserChoice(race, START_MENU_OPTIONS);
	if (raceTypeCode == 0)
		return;
	
	// по числу типа гонки, получение строкового типа гонки
	// by number of race type, getting string race type
	std::string raceType = race.chooseRaceType(raceTypeCode);

	// очистка терминального (консольного) окна в зависимости от системы
	// clearing the terminal (console) window depending on the system
	race.clearTerminal();

	// получение дистанции от пользователя
	// getting distance from the user
	int distance = getDistance(race);

	race.clearTerminal();

	// перемешивания ТС, чтобы они были не по порядку
	// mixing the vehicles so that they are not in order
	race.shuffleVehicles(allVehicles);

	// зарегистрированные ТС на гонку
	// registered vehicles for the race
	std::vector<Vehicle*> registeredVehicles;

	// меню для регистрации ТС на гонку
	// menu for registering a vehicle for the race
	registrationVehicleMenu(registeredVehicles, allVehicles, 
							raceType, distance, race);

	startOrRegistrationMenu(registeredVehicles, allVehicles, 
							race, raceType, distance);

	againOrExitMenu(race, allVehicles);
}

/*
* получение числа выбора типа гонки и типа ТС с обработкой некорректного ввода
сделано через рекурсию, чтобы избежать бесконечного цикла, пока пользователь
не введет корректного число
* obtaining the number for selecting the race type and vehicle type with 
processing of incorrect input is done through recursion to avoid an 
endless loop until the user enters the correct number
*/
int getUserChoice(Race& race, int limit)
{
	try
	{
		int choice;

		std::cout << "Enter your choice: ";
		std::cin >> choice;

		/*
		* так как тип переменной для записи кода int, то если игрок ввел не 
		число (std::cin.fail()) или если игрок ввел число, но после цифры 
		при вводе стоит не знак переноса на новую строку, а какие-либо ещеэ
		символы (std::cin.peek() != '\n'), то запускается обработка неверного
		ввода
		* since the type of the variable for writing the code is int, then if 
		the player entered not a number (std::cin.fail()) or if the player 
		entered a number, but after the number when entering there is not 
		a new line sign, but some other characters (std::cin.peek() != '\n'),
		then processing of invalid input is started
		*/
		if (std::cin.fail() || std::cin.peek() != '\n')
			race.handleInvalidInput();

		/*
		* если игрок ввел число, но не в заданных рамках, то запускается
		обработка данного события
		* if the player entered a number, but not within the specified limits,
		then processing of this event is triggered
		*/
		if (choice < EXIT || choice > limit)
			race.handleInputWinthin();

		return choice;
	}
	catch (const RacingException& err)
	{
		std::cerr << err.what() << "\n";

		return getUserChoice(race, limit);
	}
}

/*
*получение дистанции с обработкой некорректного ввода
сделано через рекурсию, чтобы избежать бесконечного цикла, пока пользователь
не введет корректное число
* obtaining the distance with processing of incorrect input is done through 
recursion to avoid an endless loop until the user enters the correct number
*/
int getDistance(Race& race)
{
	try
	{
		int distance;

		std::cout << "Indicate the length of the distance (must be positive): ";
		std::cin >> distance;

		/*
		* так как тип переменной для записи кода int, то если игрок ввел не 
		число (std::cin.fail()) или если игрок ввел число, но после цифры 
		при вводе стоит не знак переноса на новую строку, а какие-либо ещеэ
		символы (std::cin.peek() != '\n'), то запускается обработка неверного
		ввода
		* since the type of the variable for writing the code is int, then if 
		the player entered not a number (std::cin.fail()) or if the player 
		entered a number, but after the number when entering there is not a new
		line sign, but some other characters (std::cin.peek() != '\n'), 
		then processing of invalid input is started
		*/
		if (std::cin.fail() || std::cin.peek() != '\n')
			race.handleInvalidInput();

		/*
		* если игрок ввел число, но не в заданных рамках, то запускается
		обработка данного события
		* if the player entered a number, but not within the specified limits, 
		then processing of this event is triggered
		*/
		if (distance <= 0)
			race.handleInputDistance();

		return distance;

	}
	catch (const RacingException& err)
	{
		std::cerr << err.what() << "\n";

		return getDistance(race);
	}
}

// меню регистрация ТС
// vehicle registration menu
void registrationVehicleMenu(std::vector<Vehicle*>& registeredVehicles,
						const std::vector<Vehicle*>& allVehicles,
						const std::string& raceType,
						const int distance,
						Race& race)
{
	// вывод сообщения о регистрации ТС и расстоянии
	// displaying a message about vehicle registration and distance
	race.registrationMessage(raceType, distance);

	// вывод списка ТС и сообщения о выборе пунктов списка
	// displaying a list of vehicles and messages about selecting list items
	race.registrationVehiclesOptions(allVehicles);

	// получение количества ТС, для передачи как предел на пользовательский ввод
	// obtaining the number of vehicles for transmission as a limit to user input
	int countVehicles = allVehicles.size();

	while (true)
	{
		// получение числа от пользователя (выбор или выход)
		// getting a number from the user (select or exit)
		int vehicleUserChoice = getUserChoice(race, countVehicles);

		// если пользователь ввел 0, то регистрация закончена
		// if the user entered 0, then registration is completed
		if (vehicleUserChoice == 0)
			break;

		race.vehicleRegistration(registeredVehicles,
								  allVehicles,
								  raceType,
								  distance,
								  vehicleUserChoice);
	}
}

// меню старта заезде, если количество зарегистрированных ТС >2
// start menu for the race, if the number of registered vehicles is >2
void startOrRegistrationMenu(std::vector<Vehicle*>& registeredVehicles,
		 const std::vector<Vehicle*>& allVehicles,
		 Race& race,
		 const std::string& raceType,
		 const int distance)
{
	// дорегистрация ТС при необходимости
	// additional vehicle registration if necessary
	bool continueRegistration = true;

	/*
	*пока не достигнуто необходимое количество ТС для гонки и пока пользователь
	выбирает дорегистрацию ТС
	* until the required number of vehicles for the race is reached and until 
	the user selects additional registration of the vehicle
	*/
	while (continueRegistration)
	{
		int limit;
		race.clearTerminal(); 

		if (registeredVehicles.size() < 2)
		{
			std::cout << "At least two vehicles must be registered for the race!\n";
			std::cout << "1. Register a vehicle.\n";
			limit = 1;
		}
		else
		{
			std::cout << "1. Register a vehicle.\n";
			std::cout << "2. Start race\n";
			limit = 2;
		}

		int choice = getUserChoice(race, limit);

		race.clearTerminal();

		switch (choice)
		{
		case(1):
			registrationVehicleMenu(registeredVehicles, allVehicles, 
									raceType, distance, race);
			break;
		case(2):
			race.printResult(registeredVehicles, distance);
			continueRegistration = false;
			break;
		}
	}
}

// меню с запуском новой гонки или выхода из игры
// menu with starting a new race or exiting the game
void againOrExitMenu(Race& race, std::vector<Vehicle*>& allVehicles)
{
	std::cout << "\n1. Run another race\n";
	std::cout << "0. Exit\n";

	int choice = getUserChoice(race, LAST_MENU_OPTIONS);

	switch (choice)
	{
	case(1):
		race.clearTerminal();
		startRace(race, allVehicles);
		break;
	case(0):
		exit(choice);
	}
}
