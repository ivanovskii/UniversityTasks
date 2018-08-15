#include <iostream>
#include <iterator>
#include "AVL.h"

void end()
{
	system("pause");
	system("cls");
}

int main()
{
	AVL Tree;
	while (true)
	{
		std::cout << "Select the action:\n1) Add new key\n2) Show Tree\n3) Remove key\n>>> ";
		switch (*std::istream_iterator <int> (std::cin))
		{
		case 1:
		{
			system("cls");
			std::cout << "Enter the key that you want to add\n>>> ";
			Tree.insert(*std::istream_iterator <int>(std::cin));
			end();
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "Entered Tree: ";
			Tree.show();
			std::cout << std::endl;
			end();
			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "Enter the key that you want to delete\n>>> ";
			Tree.remove(*std::istream_iterator <int>(std::cin));
			end();
			break;
		}
		case 4:
			system("cls");
			Tree.check();
			end();
			break;
		default:
		{
			system("cls");
			std::cout << "Oooops! Something was wrong!\n";
			end();
			break;
		}
		}
	}
	system("pause");
}