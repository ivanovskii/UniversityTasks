#include "ParseTree.h"
#include <iostream>
#include <string>

void end()
{
	system("pause");
	system("cls");
}

int main()
{
	ParseTree expression;
	std::string expr;
	while (true)
	{
		int choice;
		std::cout << "Select an action\n1) Enter the expression\n2) Show expression\n3) Calculate the expression\n4) Exit\n\n>>> ";
		std::cin >> choice;
		system("cls");
		if (choice == 4) break;
		switch (choice)
		{
		case 1:
		{
			std::cout << "Enter the expression\n>>> ";
			std::cin >> expr;
			expression.SetExpression(expr);
			expression.MakeTree();
			end();
			break;
		}
		case 2:
		{
			expression.Show();
			end();
			break;
		}
		case 3:
			std::cout << expression.CalcTree();
			end();
			break;
		default:
		{
			std::cout << "Ooops! Entered data is incorrect.\n";
			end();
		}
		}
	}
}