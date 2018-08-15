#include <iostream>
#include <string>
#include "RLE.h"

int main()
{
	RLE str;
	int choice;
	while (true)
	{
		std::cout << "Select action:\n1) Enter the string\n2) Compress the string\n3) Decompress the string\n4) Show the string\n5) Exit\n>>> ";
		std::cin >> choice;
		if (choice == 5) break;
		system("cls");
		switch (choice)
		{
		case 1:
		{
			std::string inputtingStr;
			std::cout << "Enter the string:\n>>> ";
			std::cin >> inputtingStr;
			str.ChangeStr(inputtingStr);
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{	
			str.Compress();
			std::cout << "Done!\n";
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			str.Decompress();
			std::cout << "Done!\n";
			system("pause");
			system("cls");
			break;
		}
		case 4:
			std::cout << "Entered string:\n" << str.GetStr() << "\n\n";
			std::cout << "Compressed string:\n" << str.GetCStr() << "\n\n";
			std::cout << "Decomressed string:\n" << str.GetDStr() << "\n\n";
			system("pause");
			system("cls");
			break;
		default:
			break;
		}
	}
}