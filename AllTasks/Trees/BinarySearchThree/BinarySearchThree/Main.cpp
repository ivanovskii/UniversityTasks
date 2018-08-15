#include <iostream>
#include "BinarySearchTree.h"


int main()
{
	setlocale(0, "");
	BinaryTreeSearch MyTree;
	while (true)
	{
		int choice = 0;
		std::cout << "Press key:\n1) Add\n2) Del\n3) Search\n4) Show\n5) Delete Tree\n6) Exit\n>>> ";
		std::cin >> choice;
		if (std::cin.fail()) //Когда происходит сбой cin
		{
			std::cout << "ERROR -- You did not enter an integer\n";
			std::cin.clear(); // очистить состояние отказа
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // заставить поток выбросить плохой ввод 
		}
		if (choice == 6) break;
		switch (choice) {
		case 1:
		{
			int key;
			std::cout << "What number you want to input?\n>>> ";
			std::cin >> key;
			MyTree.Add(key);
			std::cout << "Well Done!\n";
			system("pause");
			system("cls");
			continue;
		}
		case 2:
		{
			int key;
			std::cout << "What key you want to delete?\n>>> ";
			std::cin >> key;
			MyTree.DeleteNode(key);
			system("pause");
			system("cls");
			continue;
		}
		case 3:
		{
			int key;
			std::cout << "What number you want to find?\n>>> ";
			std::cin >> key;
			if (MyTree.Find(key)) std::cout << "We found it number!\n";
			else std::cout << "There is no such key\n";
			system("pause");
			system("cls");
			continue;
		}
		case 4:
		{
			MyTree.Show();
			system("pause");
			system("cls");
			continue;
		}
		case 5:
		{
			MyTree.Clear();
			std::cout << "Well done!\n";
			system("pause");
			system("cls");
			continue;
		}
		default:
		{
			system("pause");
			system("cls");
			continue;
		}
		}
	}
	system("pause");
	return 0;
}