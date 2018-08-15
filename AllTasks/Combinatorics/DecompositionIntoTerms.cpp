#include <stdio.h>
#include <iostream>
#include <vector>

int size = 0;
std::vector <std::vector <int>> matrix;

void PrintData(int num)
{
	for (int i = size-1; i >= 0; i--)
	{
		for (int j = 0; j < num; j++)
		{
			if (matrix[i][j] != 0) std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void SaveData(std::vector <int> arr)
{
	size++;
	matrix.push_back(arr);
}

void Split(int num, std::vector <int> arr, int q)
{
	int start = 1;
	if (num <= 0)
	{
		SaveData(arr);
		return;
	}
	if (q > 0) start = arr[q - 1]; // новый элемент не меньше Arr[q-1]
	for (int i = start; i <= num; i++) // перебрать все до num
	{
		arr[q] = i;
		Split(num - i, arr, q + 1); // рекурсивный вызов
	}
}

int main()
{
	int num;
	std::cin >> num;
	std::vector <int> arr(num);
	Split(num, arr, 0);
	PrintData(num);
	system("pause");
}
