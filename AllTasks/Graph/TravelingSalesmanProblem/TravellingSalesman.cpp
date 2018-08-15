//'-1' отмечается невозможность добраться из одной вершины в другую в матрице смежности
//Путь начинается всегда с вершины 1

#include <iostream>
#include <assert.h>
#include <vector>
#include <iterator>
#include <algorithm>

std::int32_t Fact(std::int32_t x)
{
	static const int table[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600 };
	assert(x >= 0);
	assert(x <= 12);
	return table[x];
}

void ZeroingMatrix(std::vector <std::vector <int>> &matrix)
{
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix.size(); j++)
			if (i = j) matrix[i][j] = -1;
}

void SetGraph(std::vector <std::vector <int>> &matrix, int size)
{
	matrix.resize(size); //Количество строк
	for (int i = 0; i < size; i++)
	{
		std::vector <int> matrixString;
		for (int j = 0; j < size; j++)
			matrixString.push_back(*std::istream_iterator <int>(std::cin));
		matrix[i] = matrixString;
	}
	ZeroingMatrix(matrix);
}

std::vector <int> TravelingSalesman(std::vector <std::vector <int>> const& matrix, std::vector <int> &permutation)
{
	std::vector <int> bestPermutation = permutation;
	int weight = INT_MAX;
	for (int i = 0; i < Fact(matrix.size() - 1); i++) //Убрать тут '- 1', чтобы путь не начинался с фиксированной первой вершины
	{
		int currentWeight = 0;
		for (int j = 0; j < matrix.size() - 1; j++)
		{
			if (matrix[permutation[j] - 1][permutation[j + 1] - 1] == -1)
			{
				currentWeight = INT_MAX;
				break;
			}
			currentWeight += matrix[permutation[j] - 1][permutation[j + 1] - 1];
		}
		if (currentWeight < weight)
		{
			weight = currentWeight;
			bestPermutation = permutation;
		}
		std::next_permutation(permutation.begin(), permutation.end());
	}
	return bestPermutation;
}

std::vector <int> TravelingSalesman(std::vector <std::vector <int>> const& matrix)
{
	std::vector <int> firstPermutation(matrix.size());
	for (int i = 1; i <= matrix.size(); i++)
		firstPermutation[i - 1] = i;
	return TravelingSalesman(matrix, firstPermutation);
}

int main()
{
	while (true)
	{
		std::cout << "What size of matrix you want to set?\n>>> ";
		std::vector <std::vector <int>> graph;
		SetGraph(graph, *std::istream_iterator <int>(std::cin));
		std::vector <int> route = TravelingSalesman(graph);
		std::cout << "Received route: ";
		for (auto num : route) std::cout << num << " ";
		std::cout << std::endl;
		system("pause");
		system("cls");
	}
}
