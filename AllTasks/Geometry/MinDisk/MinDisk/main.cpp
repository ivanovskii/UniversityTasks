#include <iostream>
#include <iterator>
#include "MinDisk.h"

void input(int amount, MinDisk &set)
{
	float x, y;
	if (amount == 0) return;
	system("cls");
	std::cout << "Fill the set:\n\n" << amount << " points left\n\n>>> ";
	std::cin >> x >> y;
	set.SetPoint(x, y);
	input(amount-1, set);
}

int main() 
{
	MinDisk NewSet;
	std::cout << "How many points you want to enter?\n>>> ";
	input(*std::istream_iterator <int> (std::cin), NewSet);
	system("cls");
	std::cout << "Entered points:\n";
	NewSet.ShowSet();
	NewSet.getCentreRadius();
	system("pause");
}