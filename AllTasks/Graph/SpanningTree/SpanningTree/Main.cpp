#include <iostream>
#include <vector>
#include "SpanningTree.h"

//Получаем весовую матрицу графа по описанию ребер
void input(std::vector <std::vector <int>> &matrix, int m)
{
	for (int i = 0; i < m; i++)
	{
		int	beginKnot, endKnot, weight;
		std::cin >> beginKnot >> endKnot >> weight;
		matrix[beginKnot - 1][endKnot - 1] = weight;
		matrix[endKnot - 1][beginKnot - 1] = weight;
	}
}

int main()
{
	int n, m; //n - количество вершин; m - количество ребер
	std::cin >> n >> m;
	std::vector <std::vector <int>> graphMatrix(n, std::vector <int>(n)); //Матрица графа
	input(graphMatrix, m); 

	SpanningTree newTree(graphMatrix);
	std::cout << newTree.GetWeight();

	system("pause");
}