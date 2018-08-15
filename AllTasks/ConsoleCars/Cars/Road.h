#pragma once

class Road
{
public:
	int lenght;
	char sym;

	Road()
	{
		lenght = 0;
	}

	Road(int len, char roadSym)
	{
		if (len < 3) lenght = 3;
		else lenght = len;
		sym = roadSym;
	}

	void showRoad(int n)
	{	
		for (int i = 0; i < n; i++)
		{
			for (int i = 0; i < lenght + 2; ++i) std::cout << sym;
			std::cout << "\n" << sym;
			for (int i = 0; i < lenght; i++) std::cout << " ";
			std::cout << sym << "\n";
		}
		for (int i = 0; i < lenght + 2; ++i) std::cout << sym;
	}
};