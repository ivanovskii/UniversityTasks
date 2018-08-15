#include <iostream>
#include <vector>
#include <ctime>
#include <conio.h>
#include "Cars.h"
#include "Road.h"

void randInput(int &roadLength, char &roadSym, int &amount, std::vector <Cars> &cars, int &numLine)
{
	srand(time(0));
	roadLength = 1 + rand() % 118;
	roadSym = char (33 + rand() % 126);
	amount = 1 + rand() % 14;
	for (int i = 0; i < amount; ++i)
	{
		int speed = 1 + rand() % 4;
		int startPosition = 1 + rand() % 3;
		char symbol = char(33 + rand() % 126);
		cars.push_back({ roadLength, speed, startPosition, numLine, symbol });
		numLine++;
	}
	system("cls");
}

void input(int &roadLength, char &roadSym, int &amount, std::vector <Cars> &cars, int &numLine)
{
	std::cout << "What length of road do you want to set?\n>>> ";
	std::cin >> roadLength;
	std::cout << "Which symbol to designate the road?\n>>> ";
	std::cin >> roadSym;
	std::cout << "How many cars you want to enter?\n>>> ";
	std::cin >> amount;
	system("cls");
	for (int i = 0; i < amount; ++i)
	{
		int speed, startPosition;
		char symbol;
		std::cout << "Enter the options of car:\n1) Speed\n2) Start position\n3) Symbol:\n\nEntered cars: ";
		std::cout << cars.size() << "\nLeft: " << amount - cars.size() << "\n\n>>> ";
		std::cin >> speed >> startPosition >> symbol;
		cars.push_back({ roadLength, speed, startPosition, numLine, symbol });
		numLine++;
		system("cls");
	}
}

int main()
{
	int roadLength, amount;
	char roadSym;
	std::vector <Cars> cars;
	int numLine = 1;

	unsigned short int choice;
	std::cout << "Choose the metod of filling:\n1) Full Random\n2) Using keyboard\n>>> ";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		randInput(roadLength, roadSym, amount, cars, numLine);
		break;
	case 2:
		input(roadLength, roadSym, amount, cars, numLine);
		break;
	}

	Road NewRoad(roadLength, roadSym);
	NewRoad.showRoad(cars.size());

	do {
		for (int i = 0; i < cars.size(); i++) cars[i].move();
		Sleep(100);
		for (int i = 0; i < cars.size(); i++) cars[i].remove();
	} while (!_kbhit());
}