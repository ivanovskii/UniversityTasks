#include <iostream>
#include <string>
#include <vector>
#include <iterator>

void inputMatrix(std::vector <std::vector <int>> &matrix, int size)
{
	std::string dummyLine;
	std::getline(std::cin, dummyLine);
	for (int i = 0; i < size; i++)
	{
		std::string str;
		std::getline(std::cin, str);
		while (str.find(' ') != -1) str.erase(str.find(' '), 1); //Очищаем строку от пробелов
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] != '0') matrix[i][(int) str[j] - 49] = 1;
		}
	}
}

void showMatrix(std::vector <std::vector <int>> matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}
}

int main()
{
	int size;
	std::cin >> size;
	std::vector <std::vector <int>> matrix(size, std::vector <int>(size));
	inputMatrix(matrix, size);
	showMatrix(matrix, size);
	system("pause");
}
